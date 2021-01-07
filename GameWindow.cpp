#include "GameWindow.h"
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))

/*
GameWindow() -> game_init() -> 
game_play() -> game_begin() -> game_run()
*/

void mainCharacter_attack( MainCharacter* main_character, Monster* monster){
    main_character->attack();
    monster->be_attacked(main_character->get_power());
}
void monster_attack(Monster* monster, MainCharacter* main_character){
    monster->attack();
    main_character->be_attacked(monster->get_power());
    // exit(0);
}

void GameWindow::game_init()
{   
    char buffer[50];
    // load image 
    // icon = al_load_bitmap("./icon.png");
    // background = al_load_bitmap("./StartBackground.jpg");

    // for(int i = 0; i < Num_TowerType; i++)
    // {
    //     sprintf(buffer, "./Tower/%s.png", TowerClass[i]);
    //     tower[i] = al_load_bitmap(buffer);
    // }

    // load window
    // al_set_display_icon(display, icon);
    // al_reserve_samples(3);

    // load music
    // sample = al_load_sample("growl.wav");
    // startSound = al_create_sample_instance(sample);
    // al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    // al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());

    // sample = al_load_sample("BackgroundMusic.ogg");
    // backgroundSound = al_create_sample_instance(sample);
    // al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    // al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());
}

bool GameWindow::mouse_hover(int startx, int starty, int width, int height)
{
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
}
void GameWindow::game_play()
{
    // cout << MON_DOC.ACTION["ABC"]<<"play"<<endl;

    int msg;

    srand(time(NULL));

    msg = -1;
    game_reset();
    game_begin();

    while(msg != GAME_EXIT)
    {
        msg = game_run();
    }

    show_err_msg(msg);
}

void GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    event_queue = al_create_event_queue();

    basic_timer = al_create_timer(1.0 / FPS);
    quater_timer = al_create_timer(8.0 / FPS);
    if(basic_timer == NULL || quater_timer == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    // font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",12,0); // load small font
    // Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    // Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(basic_timer));
    al_register_event_source(event_queue, al_get_timer_event_source(quater_timer));
    game_init();
}

void GameWindow::game_begin()
{
    draw_running_map();

    // al_play_sample_instance(startSound);
    // while(al_get_sample_instance_playing(startSound));
    // al_play_sample_instance(backgroundSound);

    al_start_timer(basic_timer);
    al_start_timer(quater_timer);
}

int GameWindow::game_run()
{
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {
        error = process_event();
    }
    return error;
}

int GameWindow::game_update()
{   /*
    update the status of every object. lives, position validation ...
    */
    if (beat_cnt == 4){ // moving tempo
        
        int next_x = main_character->get_next_x();
        int next_y = main_character->get_next_y();
        int pos_x = main_character->get_x();
        int pos_y = main_character->get_x();
        for(auto it=monsters.begin(); it!=monsters.end(); ) {
            Monster* monster = (*it);

            if(next_x == monster->get_x() && next_y == monster->get_y()) {
                // check if main character kill monsters
                mainCharacter_attack( main_character, monster);
                if (monster->is_dead()){
                    rewards.push_back(new Coin(1, monster->get_x(), monster->get_y()));
                    it = monsters.erase(it);
                    delete monster;

                }else it++;
            }else if ( next_x == monster->get_next_x() && next_y == monster->get_next_y()){
                // check if monster kill main character
                monster_attack(monster, main_character);
                if (main_character->is_dead()){
                    // exit(0); // game over
                }
                it++;
            }else {
                it++;
            }
        }
        for (auto monster : monsters){
            monster->move();
        }
        main_character->move();
        beat_cnt = 0;
    }

   
   return GAME_CONTINUE;
}

void GameWindow::game_reset()
{   /*
    1. clear object 
    2. new object
    */
    for (auto& monster : monsters){
        delete monster;
    }
    monsters.clear();
    for (auto reward : rewards){
        delete reward;
    }
    rewards.clear();

    // stop sample instance
    // al_stop_sample_instance(backgroundSound);
    // al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(basic_timer);
    al_stop_timer(quater_timer);

    // init game objects
    game_map = new Map();
    // monsters.push_back(moo);

    // monsters.push_back(new GreenSlime());
    // monsters.push_back(new BlueSlime());
    monsters.push_back(new BlueSlime());
    // monsters.push_back(new RedBat());
    main_character = new MainCharacter("assets/main/TEMP_medic.png");
}

void GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    // al_destroy_font(font);
    // al_destroy_font(Medium_font);
    // al_destroy_font(Large_font);
    al_destroy_timer(quater_timer);
    al_destroy_timer(basic_timer);

    // al_destroy_bitmap(icon);
    // al_destroy_bitmap(background);

    // al_destroy_sample(sample);
    // al_destroy_sample_instance(startSound);
    // al_destroy_sample_instance(backgroundSound);

}

int GameWindow::process_event()
{
    int i;
    int instruction = GAME_CONTINUE;



    al_wait_for_event(event_queue, &event);
    redraw = false;

    if(event.type == ALLEGRO_EVENT_TIMER) {
        if (event.timer.source == quater_timer){
            redraw = true;
            beat_cnt ++ ;
            // monster's animation
            for (auto monster : monsters){
                monster->change_action();
            }
            if (beat_cnt == 4) { // 4 beat move once
                // monsters early move
                for (auto monster : monsters){
                    monster->early_move();
                }
                // main character early move
                main_character->early_move();
            }else {
                //main_character->change_dir(NON);
            }
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        redraw = false;
        switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_P:
                /*TODO: handle pause event here*/
                break;
            case ALLEGRO_KEY_M:
                mute = !mute;
                if(mute)
                    al_stop_sample_instance(backgroundSound);
                else
                    al_play_sample_instance(backgroundSound);
                break;
            case ALLEGRO_KEY_UP:
                main_character->change_dir(UP);
                break;
            case ALLEGRO_KEY_DOWN:
                main_character->change_dir(DOWN);
                break;
            case ALLEGRO_KEY_LEFT:
                main_character->change_dir(LEFT);
                break;
            case ALLEGRO_KEY_RIGHT:
                main_character->change_dir(RIGHT);
                break;

      
        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if(event.mouse.button == 1) {
        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
    }

    if(redraw) {
        // update each object in game
        instruction = game_update();

        // Re-draw map
        draw_running_map();
        redraw = false;
    }

    return instruction;
}

void GameWindow::draw_running_map()
{
    unsigned int i, j;
    al_clear_to_color(al_map_rgb(0, 0, 0));

    // 2 times bigger
    ALLEGRO_TRANSFORM prev, trans;
    al_copy_transform(&prev, al_get_current_transform());
    al_identity_transform(&trans);
    al_scale_transform(&trans, 4, 4);
    al_use_transform(&trans);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    game_map -> draw();
    for (auto monster : monsters){
        monster -> draw();
    }
    main_character -> draw();
    for (auto reward : rewards){
        reward -> draw();
    }
    al_use_transform(&prev);

    // al_draw_filled_rectangle(FIELD_HEIGHT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, al_map_rgb(100, 100, 100));
    al_flip_display();
}

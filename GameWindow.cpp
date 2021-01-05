#include "GameWindow.h"
#include "global.h"
#include <iostream>

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))





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

    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);

    if(timer == NULL)
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

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    game_init();
}

void GameWindow::game_begin()
{
    draw_running_map();

    // al_play_sample_instance(startSound);
    // while(al_get_sample_instance_playing(startSound));
    // al_play_sample_instance(backgroundSound);

    al_start_timer(timer);
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

}

void GameWindow::game_reset()
{
    /*
    new object
    */
    // stop sample instance
    // al_stop_sample_instance(backgroundSound);
    // al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(timer);

    // init game objects
    game_map = new Map();
    monsters.push_back(new Monster("assets/monster/undead_santa.png"));
    mainCharacter = new MainCharacter("assets/main/TEMP_medic.png");
}

void GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    // al_destroy_font(font);
    // al_destroy_font(Medium_font);
    // al_destroy_font(Large_font);

    al_destroy_timer(timer);

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

    // offset for pause window
    int offsetX = FIELD_WIDTH/2 - 200;
    int offsetY = FIELD_HEIGHT/2 - 200;

    al_wait_for_event(event_queue, &event);
    redraw = false;

    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(event.timer.source == timer) {
            redraw = true;

                al_stop_timer(timer);
                // return GAME_EXIT;
        
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        redraw = true;
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
                mainCharacter -> move(UP);
                break;
            case ALLEGRO_KEY_DOWN:
                mainCharacter -> move(DOWN);
                break;
            case ALLEGRO_KEY_LEFT:
                mainCharacter -> move(LEFT);
                break;
            case ALLEGRO_KEY_RIGHT:
                mainCharacter -> move(RIGHT);
                break;

      
        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if(event.mouse.button == 1) {
            // mouse_hover(0, 0, field_width, field_height)
            // 
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
    al_clear_to_color(al_map_rgb(100, 100, 100));
    game_map -> draw();
    for (auto monster : monsters){
        monster -> draw();
    }
    mainCharacter -> draw();

    al_use_transform(&prev);

    // al_draw_filled_rectangle(FIELD_HEIGHT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, al_map_rgb(100, 100, 100));
    al_flip_display();
}

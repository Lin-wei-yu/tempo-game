#include "GameWindow.h"
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

// #define min(a, b) ((a) < (b)? (a) : (b))
// #define max(a, b) ((a) > (b)? (a) : (b))


/*
GameWindow() -> game_init() ->
game_play() -> game_begin() -> game_run()
*/

// 
TEMPO_ACC tempo_acc = UN_CERTAIN;


void mainCharacter_attack( MainCharacter* main_character, Monster* monster){
    main_character->attack();
    monster->be_attacked(main_character->get_power());
}
void monster_attack(Monster* monster, MainCharacter* main_character){
    monster->attack();
    main_character->be_attacked(monster->get_power());
}
void item_attack_monster(Item* item, Monster* monster){
    monster->be_attacked(item->get_power());
}
void item_attack_mainCharacter(Item* item, MainCharacter* main_character){
    main_character->be_attacked(item->get_power());
}

void GameWindow::load_monster_imgs(){
    monster_imgs["green_slime"] = al_load_bitmap("assets/monster/slime_green.png");
    monster_imgs["blue_slime"] = al_load_bitmap("assets/monster/slime_blue.png");
    monster_imgs["red_bat"] = al_load_bitmap("assets/monster/bat_red.png");
    monster_imgs["zombie"] = al_load_bitmap("assets/monster/zombie.png");
    monster_imgs["skeleton"] = al_load_bitmap("assets/monster/skeleton.png");
    monster_imgs["black_skeleton"] = al_load_bitmap("assets/monster/skeleton_black.png");
    monster_imgs["stone_golem"] = al_load_bitmap("assets/monster/golem_stone.png");
}
void GameWindow::load_coin_imgs(){
    coin_imgs[1] = al_load_bitmap("assets/reward/resource_coin1.png");
    coin_imgs[2] = al_load_bitmap("assets/reward/resource_coin2.png");
    coin_imgs[3] = al_load_bitmap("assets/reward/resource_coin3.png");
    coin_imgs[4] = al_load_bitmap("assets/reward/resource_coin4.png");
    coin_imgs[5] = al_load_bitmap("assets/reward/resource_coin5.png");
    coin_imgs[6] = al_load_bitmap("assets/reward/resource_coin6.png");
    coin_imgs[7] = al_load_bitmap("assets/reward/resource_coin7.png");
    coin_imgs[8] = al_load_bitmap("assets/reward/resource_coin8.png");
    coin_imgs[9] = al_load_bitmap("assets/reward/resource_coin9.png");
    coin_imgs[10] = al_load_bitmap("assets/reward/resource_coin10.png");
}
void GameWindow::load_item_imgs(){
    // item.
    item_imgs["bomb"] = al_load_bitmap("assets/item/bomb.png");
    item_imgs["shovel"] = al_load_bitmap("assets/item/shovel_basic.png");
    item_imgs["dagger"] = al_load_bitmap("assets/item/weapon_dagger.png");
    item_imgs["torch"] = al_load_bitmap("assets/item/torch.png");   
    item_imgs["advanced_shovel"] = al_load_bitmap("assets/item/shovel_advanced.png");   
    item_imgs["longsword"] = al_load_bitmap("assets/item/longsword.png");   
    item_imgs["advanced_torch"] = al_load_bitmap("assets/item/torch_advanced.png");   

    // slot.
    item_imgs["bomb_slot"] = al_load_bitmap("assets/item/bomb_slot.png");  
    item_imgs["shovel_slot"] = al_load_bitmap("assets/item/shovel_slot.png");
    item_imgs["attack_slot"] = al_load_bitmap("assets/item/attack_slot.png");
    item_imgs["torch_slot"] = al_load_bitmap("assets/item/torch_slot.png");
}
void GameWindow::load_character_imgs(){
    character_imgs["aria"] = al_load_bitmap("assets/main/clone_aria.png");
    character_imgs["cadencce"] = al_load_bitmap("assets/main/clone_cadencce.png");
}
void GameWindow::load_number_imgs(){
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_0.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_1.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_2.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_3.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_4.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_5.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_6.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_7.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_8.png"));
    number_imgs.push_back(al_load_bitmap("assets/font/number_white_9.png"));
}
void GameWindow::load_heart_imgs(){
    heart_imgs["empty"] = al_load_bitmap("assets/main/heart_empty.png");
    heart_imgs["half"] = al_load_bitmap("assets/main/heart_half.png");
    heart_imgs["full"] = al_load_bitmap("assets/main/heart.png");
}
void GameWindow::load_other_imgs(){
    other_imgs["coin_icon"] = al_load_bitmap("assets/main/hud_coins.png");
    other_imgs["alphabet"] = al_load_bitmap("assets/font/alphabet_white.png");
    other_imgs["missed"] = al_load_bitmap("assets/font/missed.png");
    other_imgs["explosion"]= al_load_bitmap("assets/item/explosion.png");
    other_imgs["tempo_heart"] = al_load_bitmap("assets/heart/TEMP_beat_heart.png");
    other_imgs["beat_marker"] = al_load_bitmap("assets/heart/TEMP_beat_marker.png");

}
void GameWindow::init_object_pos(){
    // monster 
    ifstream monster_pos;
    string s;
    monster_pos.open("map/monster.txt");
    int w=0, h=0;
    while(getline(monster_pos, s)) {
        w = 0;
        for(auto symbol: s) {
            switch(symbol){
                case 'A':
                    monsters.push_back(new BlackSkeleton(monster_imgs["black_skeleton"], heart_imgs,GRID_SIZE*w,GRID_SIZE* h));
                    break;
                case 'B':
                    monsters.push_back(new BlueSlime(monster_imgs["blue_slime"], heart_imgs, GRID_SIZE*w, GRID_SIZE*h));
                    break;
                case 'C':
                    monsters.push_back(new GreenSlime(monster_imgs["green_slime"], heart_imgs, GRID_SIZE*w, GRID_SIZE*h));
                    break;
                case 'D':
                    monsters.push_back(new RedBat(monster_imgs["red_bat"], heart_imgs, GRID_SIZE*w, GRID_SIZE*h));
                    break;
                case 'E':
                    monsters.push_back(new Skeleton(monster_imgs["skeleton"], heart_imgs, GRID_SIZE*w, GRID_SIZE*h));
                    break;
                case 'F':
                    monsters.push_back(new StoneGolem(monster_imgs["stone_golem"], heart_imgs, GRID_SIZE*w, GRID_SIZE*h));
                    break;
                case 'G':
                    monsters.push_back(new Zombie(monster_imgs["zombie"], heart_imgs, GRID_SIZE*w, GRID_SIZE*h));
                    break;
                default :
                    break;
            }   
            w++;
        }
        h++;
    }
    monster_pos.close();
}
void GameWindow::game_init()
{   /*
    load stuff from memory
    */
    char buffer[50];

    // load image
    
    icon = al_load_bitmap("assets/main/icon.png");
    load_monster_imgs();
    load_coin_imgs();
    load_item_imgs();
    load_character_imgs();
    load_number_imgs();
    load_heart_imgs();
    load_other_imgs();
    
    // load window
    al_set_display_icon(display, icon);
    al_reserve_samples(3);

    //load music
    // sample = al_load_sample("assets/sound/zone1_1_1.ogg");
    // startSound = al_create_sample_instance(sample);
    // al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    // al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());

    // sample = al_load_sample("assets/music/zone5_2_2.ogg");
    // backgroundSound = al_create_sample_instance(sample);
    // al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    // al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());

    // create new bitmap for camera
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR | ALLEGRO_NO_PRESERVE_TEXTURE);
    tmp_bitmap = al_create_bitmap(WINDOW_WIDTH, WINDOW_HEIGHT);
    
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
    // for full window
    // al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    event_queue = al_create_event_queue();

    quater_timer = al_create_timer(8.0 / FPS);
    if(quater_timer == NULL)
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

    // font = al_load_ttf_font("Caviar_Dreams_Bold.ttf", 72, 0); 

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(quater_timer));
    game_init();
}

void GameWindow::game_begin()
{
    /*
    create every object
    */

    // init game objects
    init_object_pos();
    game_map = new Map();
    

    main_character = new Aria(character_imgs["aria"], number_imgs, heart_imgs, other_imgs);

    //test
    main_character->find_item(new Shovel(item_imgs["shovel"],item_imgs["shovel_slot"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));
    main_character->find_item(new Bomb(item_imgs["bomb"],item_imgs["bomb_slot"], other_imgs["explosion"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));
    main_character->find_item(new Bomb(item_imgs["bomb"],item_imgs["bomb_slot"], other_imgs["explosion"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));
    main_character->find_item(new Dagger(item_imgs["dagger"],item_imgs["attack_slot"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));
    main_character->find_item(new Torch(item_imgs["torch"],item_imgs["torch_slot"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));
    // main_character->find_item(new LongSword(item_imgs["longsword"],item_imgs["attack_slot"]));
    // main_character->find_item(new AdvancedShovel(item_imgs["advanced_shovel"],item_imgs["shovel_slot"]));
    main_character->find_item(new AdvancedTorch(item_imgs["advanced_torch"],item_imgs["torch_slot"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));


    items.push_back(new AdvancedShovel(item_imgs["advanced_shovel"],item_imgs["shovel_slot"], number_imgs, GRID_SIZE * 24,GRID_SIZE * 4));
    tempo_heart = new TempoHeart(other_imgs["tempo_heart"], other_imgs["beat_marker"], other_imgs["missed"]);
    

    draw_running_map();

    // al_play_sample_instance(startSound);
    // while(al_get_sample_instance_playing(startSound));
    // al_play_sample_instance(backgroundSound);

    // al_start_timer(quater_timer);
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

    int pos_x = main_character->get_x();
    int pos_y = main_character->get_y();
    int next_x = -1;
    int next_y = -1;

    if (beat_cnt == BEAT_PER_TEMPO){
        // character move , monster move.
        // main character next-step
        // 1. kill monster 
        // 2. stucked by wall 
        // 3. remove wall
        // 4. move normally
        if (main_character->get_tmp_dir()!=NON){
            // move perfect!
            main_character->early_move();
            next_x = main_character->get_next_x();
            next_y = main_character->get_next_y();

            for(auto monster : monsters) {
                monster->early_move(pos_x, pos_y);
                if(next_x == monster->get_x() && next_y == monster->get_y()) {
                    // check if main character kill monsters
                    mainCharacter_attack( main_character, monster);
                }else if (next_x == monster->get_next_x() && next_y == monster->get_next_y()){
                    // check if monster kill main character
                    monster_attack(monster, main_character);
                } 
            }
            if(game_map->map_type[next_y / GRID_SIZE][next_x / GRID_SIZE] == BlockType::ROAD || game_map->map_type[next_y / GRID_SIZE][next_x / GRID_SIZE] == BlockType::SHOP_FLAG) {
                        main_character->move();
            }
            else if(main_character->shovable(game_map->get_block(next_x / GRID_SIZE, next_y / GRID_SIZE))) {
                game_map->delete_wall(next_x / GRID_SIZE, next_y / GRID_SIZE, main_character->get_shovel_img());
                main_character->stuck();
            }
            else if(game_map->map_type[next_y / GRID_SIZE][next_x / GRID_SIZE] == BlockType::GOAL) {
                game_status = GAME_OVER;
            }
            else {
                main_character->stuck();
            }

        }else{
            // already move;
            for (auto monster : monsters){
                 monster->early_move(pos_x, pos_y);
                 if (pos_x == monster->get_next_x() && pos_y == monster->get_next_y()){
                    monster_attack(monster, main_character); 
                 }
            }
        }
       
        // monster next-step
        set<pair<int, int>> pos_set;
        for (auto monster : monsters){
            int idx_x = monster->get_next_x() / GRID_SIZE;
            int idx_y = monster->get_next_y() / GRID_SIZE;
            if(game_map->map_type[idx_y][idx_x] == BlockType::ROAD || game_map->map_type[idx_y][idx_x] == BlockType::SHOP_FLAG) {
                if (pos_set.find(make_pair(idx_x, idx_y))==pos_set.end()){
                     // this pos haven‘t be used.
                     pos_set.insert(make_pair(idx_x, idx_y));
                     monster->move();
                 }else monster->stuck();
            }
            else {
                // zombie need to change direction if hit wall
                if(monster->get_name() == "zombie") {
                    monster->change_direction();
                }
            }
        }
        tempo_acc = UN_CERTAIN;
        beat_cnt = 0;
    }else if (beat_cnt >= 0){
        // moved good.
        // character move, monster stayed.

        // main character next-step
        // 1. kill monster 
        // 2. stucked by wall 
        // 3. remove wall
        // 4. move normally
        if (main_character->get_tmp_dir()!=NON){
            tempo_acc = GOOD;

            main_character->early_move();
            next_x = main_character->get_next_x();
            next_y = main_character->get_next_y();
            for (auto monster : monsters){
                if (next_x == monster->get_x() && next_y == monster->get_y()){
                    mainCharacter_attack( main_character, monster);
                }
            }
            if(game_map->map_type[next_y / GRID_SIZE][next_x / GRID_SIZE] == BlockType::ROAD || game_map->map_type[next_y / GRID_SIZE][next_x / GRID_SIZE] == BlockType::SHOP_FLAG) {
                    main_character->move();
            }
            else if(main_character->shovable(game_map->get_block(next_x / GRID_SIZE, next_y / GRID_SIZE))) {
                game_map->delete_wall(next_x / GRID_SIZE, next_y / GRID_SIZE, main_character->get_shovel_img());
                main_character->stuck();
            }
            else if(game_map->map_type[next_y / GRID_SIZE][next_x / GRID_SIZE] == BlockType::GOAL) {
                game_status = GAME_OVER;
            }
            else {
                main_character->stuck();
            }
        }

    }else {
        // moved missed.
        if (main_character->get_tmp_dir() != NON){
            tempo_acc = BAD;
            tempo_heart->miss_tempo();
            main_character->stuck();
        }
    }
    // after move. 

    // find coin;
    for (auto it=coins.begin(); it!=coins.end(); ){
        if (main_character->get_x() == (*it)->get_x() && main_character->get_y() == (*it)->get_y()){
            main_character->find_money((*it)->get_value());
            Coin* coin = (*it);
            delete coin;
            it = coins.erase(it);

        }else it++;
    }
    // find item;
    for (auto it=items.begin(); it!=items.end(); it++){
        if (main_character->get_x() == (*it)->get_x() && main_character->get_y() == (*it)->get_y()){
            if((*it)->get_value() <= main_character->get_num_coin()) {
                Item* ret_item = main_character->find_item((*it));
                ///////
                items.erase(it);
                if (ret_item != NULL) {
                    // put the return item to original position.
                    ret_item->release(pos_x, pos_y);
                    items.push_back(ret_item);
                    
                }
            }
            break;
        }
    }

    // bombing items;
    for (auto it=bombing_items.begin(); it!=bombing_items.end();){
        int center_x = (*it)->get_x();
        int center_y = (*it)->get_y();
        Range range = (*it)->get_range();
        if ((*it)->is_attacking()){

            // item attack monster.
            for(auto monster : monsters) {
                if ((monster->get_x() <= (center_x+range.get_right())) && (monster->get_x() >= (center_x-range.get_left())) 
                    && (monster->get_y() <= (center_y+range.get_down())) && (monster->get_y() >= (center_y-range.get_up()))){
                    item_attack_monster((*it), monster);
                }
            }
            // item attack main-character.
            if (main_character->get_x() <= center_x+range.get_right() && main_character->get_x() >= center_x-range.get_left() 
                && main_character->get_y() <= center_y+range.get_down() && main_character->get_y() >= center_y-range.get_up()){
                item_attack_mainCharacter((*it), main_character);
            }

        }
        if ((*it)->need_recycle()){
            it = bombing_items.erase(it);
        }else it++;
    }

    // check if monster still alive.
    for(auto it=monsters.begin(); it!=monsters.end(); ) {
         Monster* monster = (*it);     
         if (monster->is_dead()){
             int drop = monster->get_drop_money();
             coins.push_back(new Coin(drop, monster->get_x(), monster->get_y(), coin_imgs[drop]));
             it = monsters.erase(it);
             delete monster;
         }else it++;
    }


   return GAME_CONTINUE;
}

void GameWindow::game_reset()
{   /*
    clear object and free memory
    */
    for (auto&& monster : monsters){
        delete monster;
    }
    monsters.clear();
    for (auto&& coin : coins){
        delete coin;
    }
    coins.clear();
    for (auto&& item : items){
        delete item;
    }
    items.clear();
    for (auto&& bombing_item : bombing_items){
        delete bombing_item;
    }
    bombing_items.clear();

    // stop sample instance
    // al_stop_sample_instance(backgroundSound);
    // al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(quater_timer);
    
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

    al_destroy_bitmap(icon);

    // al_destroy_sample(sample);
    // al_destroy_sample_instance(startSound);
    // al_destroy_sample_instance(backgroundSound);


    // free image
    for (auto&& coin_img : coin_imgs){
        al_destroy_bitmap(coin_img.second);
    }
    coin_imgs.clear();
    for (auto&& monster_img :monster_imgs){
        al_destroy_bitmap(monster_img.second);
    }
    monster_imgs.clear();
    for (auto&& item_img: item_imgs){
        al_destroy_bitmap(item_img.second);
    }
    item_imgs.clear();
    for (auto&& character_img: character_imgs){
        al_destroy_bitmap(character_img.second);
    }
    character_imgs.clear();
    for (auto&& number_img : number_imgs){
        al_destroy_bitmap(number_img);
    }
    number_imgs.clear();
    for (auto&& heart_img : heart_imgs){
        al_destroy_bitmap(heart_img.second);
    }
    heart_imgs.clear();
    for (auto&& other_img: other_imgs){
        al_destroy_bitmap(other_img.second);
    }
    other_imgs.clear();
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
            // passing beat to every object that can move with tempo.
            for (auto monster : monsters){
                monster->pass_beat();
            }
            tempo_heart->pass_beat();
            game_map->pass_beat();
            main_character->pass_beat();
            // for (auto item : items){
            //     item->pass_beat();
            // }
            for (auto bombing_item : bombing_items){
                bombing_item->pass_beat();
            }
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        redraw = true;
        switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_P:
                if(game_status == GAME_RUN) {
                    game_status = GAME_PAUSE;
                    // al_draw_text(font, al_map_rgb_f(1, 1, 1), 350, 480, 0, "PRESS \"P\" TO CONTINUE");
                    al_flip_display();
                    al_stop_timer(quater_timer);
                }
                else if(game_status == GAME_PAUSE) {
                    game_status = GAME_RUN;
                    al_start_timer(quater_timer);
                }
                break;
            case ALLEGRO_KEY_M:
                mute = !mute;
                // if(mute)
                //     al_stop_sample_instance(backgroundSound);
                // else
                //     al_play_sample_instance(backgroundSound);
                break;
            case ALLEGRO_KEY_UP:
                if(game_status == GAME_RUN) main_character->change_dir(UP);
                break;
            case ALLEGRO_KEY_DOWN:
                if(game_status == GAME_RUN) main_character->change_dir(DOWN);
                break;
            case ALLEGRO_KEY_LEFT:
                if(game_status == GAME_RUN) main_character->change_dir(LEFT);
                break;
            case ALLEGRO_KEY_RIGHT:
                if(game_status == GAME_RUN) main_character->change_dir(RIGHT);
                break;
            case ALLEGRO_KEY_ENTER:
                if(game_status == GAME_BEGIN) {
                    game_status = GAME_RUN;
                    al_start_timer(quater_timer);
                }
                // else if(game_status == GAME_RUN) {
                //     game_status = GAME_OVER;
                // }
                else if(game_status == GAME_OVER) {
                    exit(0);
                }
                break;
            case ALLEGRO_KEY_SPACE:
                Item* item = main_character->release_bomb("space");
                if ( item != NULL){
                    bombing_items.push_back(item);
                }
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
    if(game_status == GAME_BEGIN) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_scaled_bitmap(al_load_bitmap("assets/mainmenu/mainmenu.png"), 0, 0, 480, 270,  0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
        // al_draw_text(font, al_map_rgb_f(1, 1, 1), 350, 800, 0, "PRESS \"ENTER\" TO START");
        al_flip_display();
    }
    else 
    if(game_status == GAME_RUN) {

        // for camera.
        ALLEGRO_BITMAP *origin_bitmap = al_get_target_bitmap();
        al_set_target_bitmap(tmp_bitmap);

        // for 2 times bigger.
        // ALLEGRO_TRANSFORM prev, trans;
        // al_copy_transform(&prev, al_get_current_transform());
        // al_identity_transform(&trans);
        // al_scale_transform(&trans, 1.9, 1.9);
        // al_use_transform(&trans);
        // al_clear_to_color(BLACK);

        
        al_clear_to_color(al_map_rgb(0, 0, 0));
        game_map -> draw_block(main_character->get_x() / GRID_SIZE, main_character->get_y() / GRID_SIZE);
        for (auto monster : monsters){
            monster->draw();
        }
        main_character -> draw();
        

        for (auto coin : coins){
            coin->draw();
        }
        for (auto item: items){
            item->draw();
        }
        for (auto bombing_item: bombing_items){
            bombing_item->draw();
        }
        

        // for 2 times bigger.
        // al_use_transform(&prev);

        // for camera.
        float VISION_WIDTH = WINDOW_WIDTH / 3;
        float VISION_HEIGHT = WINDOW_HEIGHT / 3;
        al_set_target_bitmap(origin_bitmap);
        al_clear_to_color(al_map_rgba_f(0, 0, 0, 1));
        al_draw_tinted_scaled_bitmap(tmp_bitmap, al_map_rgba_f(1, 1, 1, 1), 
                            main_character->get_x() - VISION_WIDTH / 2, 
                            main_character->get_y() - VISION_HEIGHT / 2, 
                            VISION_WIDTH, VISION_HEIGHT, 
                            0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
        // small map
        al_draw_scaled_bitmap(tmp_bitmap, main_character->get_x() - WINDOW_WIDTH / 3, 
                            main_character->get_y() - WINDOW_HEIGHT / 3, 
                            WINDOW_WIDTH / 1.5, WINDOW_HEIGHT / 1.5, 
                            GRID_SIZE * 50, GRID_SIZE * 30, WINDOW_WIDTH / 8, WINDOW_HEIGHT / 8, 0);
        main_character -> draw_life_and_coin();
        main_character -> draw_items();
        tempo_heart->draw();
        al_flip_display();
    }
    else if(game_status == GAME_OVER) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_flip_display();
    }
}

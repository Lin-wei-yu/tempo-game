#include "MainCharacter.h"
MainCharacter::MainCharacter(ALLEGRO_BITMAP* img, vector<ALLEGRO_BITMAP*>& number_imgs,
                                map<string, ALLEGRO_BITMAP*>& heart_imgs, map<string, ALLEGRO_BITMAP*>& other_imgs){
    this -> img = img;
    this -> number_imgs = number_imgs;
    this -> heart_imgs = heart_imgs;
    this -> coin_img = other_imgs["coin_icon"];
    this -> alphabet_img = other_imgs["alphabet"];
    pos_x = GRID_SIZE * 24;
    pos_y = GRID_SIZE * 3;
    power = 1;
    num_coin = 0;
    next_x = pos_x;
    next_y = pos_y;
    cur_tempo = 0;
    cur_action = 0;
    beat_cnt = 0;
    jumping = false;
    tmp_dir = NON;
    move_status = stay;
    body_status = healthy;
}
MainCharacter::~MainCharacter(){
}

void MainCharacter::draw(){
    // draw chracter
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    int sw = w / num_action; 
    int sh = h / 2;
    int offset_y = (jumping==true) ? JUMP_HIEIGHT : 0 ;
    offset_y += CHARACTER_OFFSET ;
    
    al_draw_scaled_bitmap(img, sw*cur_action, 0, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    jumping = false;
    // al_draw_scaled_bitmap(img, 0, 0, w/2, h/2, pos_x, pos_y - CHARACTER_OFFSET, w/2, h/2, 0);
}
void MainCharacter::move(){
    if (move_status == leave && body_status == healthy){
        if (pos_x != next_x || pos_y != next_y){
            jumping = true;
        }
        pos_x = next_x;
        pos_y = next_y;
    }
    move_status = stay;
    body_status = healthy;
    tmp_dir = NON;
}
void MainCharacter::stuck(){
    move_status = stay;
    body_status = healthy;
    tmp_dir = NON;
}
void MainCharacter::early_move(){
    cur_tempo ++;
    if (cur_tempo == tempo){
        move_status = leave;
        body_status = healthy;
        // waking path
        switch (tmp_dir)
        {
            case UP:
                next_x = pos_x;
                next_y = pos_y - GRID_SIZE;
                break;
            case DOWN:
                next_x = pos_x;
                next_y = pos_y + GRID_SIZE;
                break;
            case LEFT:
                next_x = pos_x - GRID_SIZE;
                next_y = pos_y;
                break;
            case RIGHT:
                next_x = pos_x + GRID_SIZE;
                next_y = pos_y;
                break;
            default:
                next_x = pos_x;
                next_y = pos_y;
                break;
        }
        tmp_dir = NON;
        cur_tempo = 0;
    }
    else {
        move_status = stay;
    }

    // printf("main:");
    // printf("%d %d %d %d",pos_x,pos_y,next_x,next_y);
    // printf("\n");
}
void MainCharacter::attack(){
    move_status = stay;
}
void MainCharacter::change_dir(DIR dir){
    tmp_dir = dir; 
}
void MainCharacter::be_attacked(float harm){
    remaining_lives = remaining_lives - harm;
    body_status = injured;
}
bool MainCharacter::is_dead(){
    return (remaining_lives <= 0);
}
float MainCharacter::get_power(){
    return power;
}
int MainCharacter::get_next_x(){
    return next_x;
}
int MainCharacter::get_next_y(){
    return next_y;
}
void MainCharacter::find_money(int num){
    num_coin += num;
}
void MainCharacter::find_item(Item* item){
    item_list[item->get_type()].push_back(item);
}
bool MainCharacter::shovable(Block block){
    for (auto shovel : item_list[shovel]){
        if (shovel->get_level() >= block.get_level() ){
            return true;
        };
    }
    return false;
}

void MainCharacter::draw_items(){
    // draw
    float enlarge_ratio = 2.5;
    int offset_x = 10;
    int offset_y = 10;
    int item_idx = 0;
    int item_height = 40*enlarge_ratio;
    for (auto shovel: item_list[shovel]){
        shovel -> show(offset_x, offset_y+item_idx*item_height, enlarge_ratio);
        item_idx ++;
    }
    for (auto bomb: item_list[bomb]){
        bomb -> show(offset_x, offset_y+item_idx*item_height, enlarge_ratio);
        item_idx ++;
    }
    for (auto attack_tool: item_list[attack_tool]){
        attack_tool -> show(offset_x, offset_y+item_idx*item_height, enlarge_ratio);
        item_idx ++;
    }
    for (auto torch: item_list[torch]){
        torch -> show(offset_x, offset_y+item_idx*item_height, enlarge_ratio);
        item_idx ++;
    }
}
void MainCharacter::draw_life_and_coin(){
    float enlarge_ratio = 2.5;
    int life_coin_pos_y = 20;
    int life_x = WINDOW_WIDTH - 480;
    int coin_x = WINDOW_WIDTH - 180;
    int num_x = WINDOW_WIDTH - 100;
    // draw lives
    int w = al_get_bitmap_width(heart_imgs["empty"]);
    int h = al_get_bitmap_height(heart_imgs["empty"]);
    float sw = w*enlarge_ratio;
    float sh = h*enlarge_ratio;

    float remain = remaining_lives;

    for (int i=0; i<starting_lives; i++){
        if (remain <= 0){
            al_draw_scaled_bitmap(heart_imgs["empty"], 0 , 0, w, h, life_x+i*sw, life_coin_pos_y, sw, sh, 0);
        }else if (remain < 1){
            al_draw_scaled_bitmap(heart_imgs["half"], 0 , 0, w, h, life_x+i*sw, life_coin_pos_y, sw, sh, 0);
        }else {
            al_draw_scaled_bitmap(heart_imgs["full"], 0 , 0, w, h, life_x+i*sw, life_coin_pos_y, sw, sh, 0);
        }
        remain --;
    }
    
    // draw coin
    w = al_get_bitmap_width(coin_img);
    h = al_get_bitmap_height(coin_img);
    sw = w*enlarge_ratio;
    sh = h*enlarge_ratio;
    al_draw_scaled_bitmap(coin_img, 0, 0, w, h, coin_x, life_coin_pos_y, sw, sh, 0); 

    // draw coin num
    w = al_get_bitmap_width(number_imgs[0]);
    h = al_get_bitmap_height(number_imgs[0]);
    sw = w*enlarge_ratio;
    sh = h*enlarge_ratio;
    int gap = 2;
    string coin_str = to_string(num_coin);
    for (int i=0; i<coin_str.size(); i++){
        int num_idx = coin_str[i] - '0';
        al_draw_scaled_bitmap(number_imgs[num_idx], 0, 0, w, h, num_x+i*(sw+gap), life_coin_pos_y+15, sw, sh, 0);
    }

}
void MainCharacter::draw_text(string str,int x, int y){
    
}
void MainCharacter::pass_beat(){
    beat_cnt++;
    if (beat_cnt == beat_of_change){
        change_action();
        beat_cnt = 0;
    }
}
void MainCharacter::change_action(){
    cur_action = cur_action + 1;
    if (cur_action == num_action) cur_action = 0;
}
Item* MainCharacter::release_bomb(string command){
    for (auto it=item_list[bomb].begin(); it!=item_list[bomb].end(); ){
        if ((*it)->get_command() == command){
            (*it)->release(pos_x, pos_y);
            it = item_list[bomb].erase(it);
            return (*it);
        }else it++;
    }
    return NULL;
}

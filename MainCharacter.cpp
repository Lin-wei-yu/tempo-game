#include "MainCharacter.h"

MainCharacter::MainCharacter(ALLEGRO_BITMAP* img){
    this -> img = img;
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

    heart_imgs.push_back(al_load_bitmap("assets/main/heart_empty.png"));
    heart_imgs.push_back(al_load_bitmap("assets/main/heart_half.png"));
    heart_imgs.push_back(al_load_bitmap("assets/main/heart.png"));
    coin_img = al_load_bitmap("assets/main/hud_coins.png");
    text_img = al_load_bitmap("assets/text/necrosans_12.png");
}
MainCharacter::~MainCharacter(){
    for (auto&& heart_img : heart_imgs){
        al_destroy_bitmap(heart_img);
    }
    heart_imgs.clear();
    al_destroy_bitmap(coin_img);
    al_destroy_bitmap(text_img);
}
void MainCharacter::draw_text(string str,int x, int y){

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
void MainCharacter::early_move(){
    cur_tempo ++;
    if (cur_tempo == tempo){
        move_status = leave;
        body_status = healthy;
        // waking path
        switch (tmp_dir)
        {
            case UP:
                next_y = pos_y - GRID_SIZE;
                break;
            case DOWN:
                next_y = pos_y + GRID_SIZE;
                break;
            case LEFT:
                next_x = pos_x - GRID_SIZE;
                break;
            case RIGHT:
                next_x = pos_x + GRID_SIZE;
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
void MainCharacter::be_attacked(float power){
    lives = lives - power;
    body_status = injured;
}
bool MainCharacter::is_dead(){
    return (lives <= 0);
}
int MainCharacter::get_power(){
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
    int offset_x = 10;
    int offset_y = 10;
    int item_idx = 0;
    int item_width = 40;
    for (auto shovel: item_list[shovel]){
        shovel -> show(offset_x, offset_y+item_idx*item_width);
        item_idx ++;
    }
    for (auto bomb: item_list[bomb]){
        bomb -> show(offset_x, offset_y+item_idx*item_width);
        item_idx ++;
    }
    for (auto attack_tool: item_list[attack_tool]){
        attack_tool -> show(offset_x, offset_y+item_idx*item_width);
        item_idx ++;
    }
    for (auto torch: item_list[torch]){
        torch -> show(offset_x, offset_y+item_idx*item_width);
        item_idx ++;
    }
}
void MainCharacter::draw_life_and_coin(){
    // draw lives
    int w = al_get_bitmap_width(heart_imgs[0]);
    int remain = lives;
    for (int i=0; i<5; i++){
        if (remain <= 0) al_draw_bitmap(heart_imgs[0], 500+i*w, 20 ,0);
        else if (remain < 1) al_draw_bitmap(heart_imgs[1], 500+i*w, 20 ,0);
        else al_draw_bitmap(heart_imgs[2], 500+i*w, 20 ,0);
        remain --;
    }
    // draw coin
    al_draw_bitmap(coin_img, 620, 20,0);
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

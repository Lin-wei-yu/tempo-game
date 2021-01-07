#include "MainCharacter.h"

MainCharacter::MainCharacter(const char* path){
    img = al_load_bitmap(path);
    pos_x = 0;
    pos_y = 0;
    power = 1;
    lives = 5;
    move_status = stay;
    body_status = healthy;
    heart_img = al_load_bitmap("assets/heart/TEMP_heart_small.png");
    num_coin = 0;
    cur_tempo = 0;
    tempo = 1;
    temp_dir = NON;
    next_x = pos_x;
    next_y = pos_y;
}
MainCharacter::~MainCharacter(){}

void MainCharacter::draw(){
    // draw chracter
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    al_draw_scaled_bitmap(img, 0, 0, w/2, h/2, pos_x, pos_y, w/2, h/2, 0);
    // draw lives
    w = al_get_bitmap_width(heart_img);
    for (int i=0; i<lives; i++){
        al_draw_bitmap(heart_img, 500+i*w, 20 ,0);
    }
}
void MainCharacter::move(){
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
    }
    move_status = stay;
    body_status = healthy;
    temp_dir = NON;
}
void MainCharacter::early_move(){
    cur_tempo ++;
    if (cur_tempo == tempo){
        move_status = leave;
        body_status = healthy;
        // waking path
        switch (temp_dir)
        {
            case UP:
                next_y = pos_y - GRID_HEIGHT;
                break;
            case DOWN:
                next_y = pos_y + GRID_HEIGHT;
                break;
            case LEFT:
                next_x = pos_x - GRID_WIDTH;
                break;
            case RIGHT:
                next_x = pos_x + GRID_WIDTH;
                break;
            default:
                next_x = pos_x;
                next_y = pos_y;
                break;
        }
        temp_dir = NON;
        cur_tempo = 0;
    }else {
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
    temp_dir = dir; 
}
void MainCharacter::be_attacked(int power){
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


#include "Zombie.h"

Zombie::Zombie(ALLEGRO_BITMAP* img):Monster(img){
    // zombie profile
    name = "zombie";
    tempo = 1;
    num_action = 8;
    power = 1;
    lives = 1;
    drop_money = 1;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;

    // 
    // cur_dir = (DIR)(rand() % DIR_KINDS);
    cur_dir = RIGHT;
}
Zombie::~Zombie(){

}
void Zombie::move(){
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
        cur_dir = tmp_dir;
    }
    move_status = stay;
    body_status = healthy;
}  
void Zombie::early_move(){
    cur_tempo++;
    if (cur_tempo == tempo){
        body_status = healthy;
        move_status = leave;
        switch(cur_dir){
            case UP:
                tmp_dir = UP;
                next_y = pos_y - GRID_HEIGHT;
                break;
            case DOWN:
                tmp_dir = DOWN;
                next_y = pos_y + GRID_HEIGHT;
                break;
            case LEFT:
                tmp_dir = LEFT;;
                next_x = pos_x - GRID_HEIGHT;
                break;
            case RIGHT:
                tmp_dir = RIGHT;;
                next_x = pos_x + GRID_HEIGHT;           
                break;
            default:
                tmp_dir = UP;
                next_y = pos_y - GRID_HEIGHT;
                break;
        }
        cur_tempo = 0;
    }else {
        move_status = stay;
    }
}   
void Zombie::draw() {
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    int sw = w / (num_action*3); 
    int sh = h / 2;
    int offset_y = (!hidden) ? 0 : sh;
    if (cur_dir == UP){
        al_draw_scaled_bitmap(img, sw*cur_action, offset_y, sw, sh, pos_x, pos_y, sw, sh, 0);
    }else if (cur_dir == LEFT){
        al_draw_scaled_bitmap(img, sw*(cur_action+8), offset_y, sw, sh, pos_x, pos_y, sw, sh, 0);
    }else if (cur_dir == RIGHT){
        al_draw_scaled_bitmap(img, sw*(cur_action+8), offset_y, sw, sh, pos_x, pos_y, sw, sh, ALLEGRO_FLIP_HORIZONTAL);
    }else {
        al_draw_scaled_bitmap(img, sw*(cur_action+16), offset_y, sw, sh, pos_x, pos_y, sw, sh, 0);
    }
}

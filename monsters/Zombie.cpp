#include "Zombie.h"

Zombie::Zombie(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y):Monster(img,heart_imgs,x,y){
    // zombie profile
    name = "zombie";
    tempo = 1;
    num_action = 8;
    power = 1;
    starting_lives = remaining_lives = 1;
    drop_money = 1;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
    // 
    cur_dir = (DIR)(rand() % DIR_KINDS);
    //cur_dir = RIGHT;
}
Zombie::~Zombie(){

}
void Zombie::early_move(int character_pos_x, int character_pos_y){
    cur_tempo++;
    if (cur_tempo == tempo){
        body_status = healthy;
        move_status = leave;
        // walking path
        switch(cur_dir){
            case UP:
                tmp_dir = UP;
                next_x = pos_x;
                next_y = pos_y - GRID_SIZE;
                break;
            case DOWN:
                tmp_dir = DOWN;
                next_x = pos_x;
                next_y = pos_y + GRID_SIZE;
                break;
            case LEFT:
                tmp_dir = LEFT;;
                next_x = pos_x - GRID_SIZE;
                next_y = pos_y;
                break;
            case RIGHT:
                tmp_dir = RIGHT;;
                next_x = pos_x + GRID_SIZE; 
                next_y = pos_y;          
                break;
            default:
                tmp_dir = UP;
                next_x = pos_x;
                next_y = pos_y - GRID_SIZE;
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
    int sh_offset = (!hidden) ? 0 : sh;

    int offset_y = (jumping==true) ? JUMP_HIEIGHT: 0;
    offset_y += CHARACTER_OFFSET;

    if (cur_dir == UP){
        al_draw_scaled_bitmap(img, sw*cur_action, sh_offset, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    }else if (cur_dir == LEFT){
        al_draw_scaled_bitmap(img, sw*(cur_action+8), sh_offset, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    }else if (cur_dir == RIGHT){
        al_draw_scaled_bitmap(img, sw*(cur_action+8), sh_offset, sw, sh, pos_x, pos_y-offset_y, sw, sh, ALLEGRO_FLIP_HORIZONTAL);
    }else {
        al_draw_scaled_bitmap(img, sw*(cur_action+16), sh_offset, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    }
    jumping = false;
}

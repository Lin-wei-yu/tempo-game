#include "Skeleton.h"

Skeleton::Skeleton(ALLEGRO_BITMAP* img):Monster(img){
    // skeleton profile.
    name =  "skeleton";
    tempo = 1;
    num_action = 8;
    power = 0.5;
    lives = 1;
    drop_money = 2;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
    sense_range = 5;
}
Skeleton::~Skeleton(){

}
void Skeleton::early_move(int character_pos_x, int character_pos_y){
    cur_tempo++;
    if (cur_tempo == tempo){
        body_status = healthy;
        move_status = leave;
        // walking path
        if ((abs(character_pos_x-pos_x) > (sense_range*GRID_SIZE)) || (abs(character_pos_y-pos_y) > (sense_range*GRID_SIZE))){
            next_x = pos_x;
            next_y = pos_y;
        }else {
            if (character_pos_x == pos_x){
                if (character_pos_y <= pos_y){
                    next_x = pos_x;
                    next_y = pos_y - GRID_SIZE;
                }else {
                    next_x = pos_x;
                    next_y = pos_y + GRID_SIZE;
                }
            }else if (character_pos_y == pos_y){
                if (character_pos_x <= pos_x){
                    next_x = pos_x - GRID_SIZE;
                    next_y = pos_y;
                }else {
                    next_x = pos_x + GRID_SIZE;
                    next_y = pos_y;
                }
            }else {
                if (cur_dir == UP || cur_dir == DOWN){
                    if (character_pos_x <= pos_x){
                        next_x = pos_x - GRID_SIZE;
                        next_y = pos_y;
                        cur_dir = LEFT;
                    }else {
                        next_x = pos_x + GRID_SIZE;
                        next_y = pos_y;
                        cur_dir = RIGHT;
                    }
                }else {
                    if (character_pos_y <= pos_y){
                        next_x = pos_x;
                        next_y = pos_y - GRID_SIZE;
                        cur_dir = UP;
                    }else {
                        next_x = pos_x;
                        next_y = pos_y + GRID_SIZE;
                        cur_dir = DOWN;
                    }                
                }
            }
        }
        cur_tempo = 0;
    }else {
        move_status = stay;
    }

}
void Skeleton::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    int sw = w / (num_action*2); 
    int sh = h / 2;
    int sh_offset = (!hidden) ? 0 : sh;

    int offset_y = (jumping==true) ? JUMP_HIEIGHT: 0;
    offset_y += CHARACTER_OFFSET;

    if (cur_dir != UP){
        al_draw_scaled_bitmap(img, sw*cur_action, sh_offset, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    }else {
        al_draw_scaled_bitmap(img, sw*(cur_action+8), sh_offset, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    }
    jumping = false;
}
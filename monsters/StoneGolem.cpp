#include "StoneGolem.h"

StoneGolem::StoneGolem(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y):Monster(img,heart_imgs,x,y){
    // stone golem profile.
    name = "stone golem";
    tempo = 4;
    num_action = 4;
    power = 2;
    starting_lives = remaining_lives = 4;
    drop_money = 4;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
    sense_range = 5;
}
StoneGolem::~StoneGolem(){
    
}
void StoneGolem::early_move(int character_pos_x, int character_pos_y){
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

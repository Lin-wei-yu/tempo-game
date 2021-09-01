#include "RedBat.h"

RedBat::RedBat(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y):Monster(img,heart_imgs,x,y){
    // red bat profile 
    name = "red_bet";
    tempo = 1;
    num_action = 4;
    power = 0.5;
    starting_lives = remaining_lives = 1;
    drop_money = 3;
    beat_of_change = BEAT_PER_TEMPO/num_action;

}
RedBat::~RedBat(){}

void RedBat::early_move(int character_pos_x, int character_pos_y){
    cur_tempo ++;
    if (cur_tempo == tempo) {
        body_status = healthy;
        move_status = leave;
        int temp_dir = rand() % (DIR_KINDS);
        switch (temp_dir)
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
            next_y = pos_y - GRID_SIZE;
            break;
        }
        cur_tempo = 0;
    }else {
        move_status = stay;
    }
}

    

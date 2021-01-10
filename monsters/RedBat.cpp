#include "RedBat.h"

RedBat::RedBat(ALLEGRO_BITMAP* img):Monster(img){
    // red bat profile 
    name = "red_bet";
    tempo = 1;
    num_action = 4;
    power = 0.5;
    lives = 1;
    drop_money = 3;
    beat_of_change = BEAT_PER_TEMPO/num_action;

}
RedBat::~RedBat(){}

void RedBat::early_move(){
    cur_tempo ++;
    if (cur_tempo == tempo) {
        body_status = healthy;
        move_status = leave;
        int temp_dir = rand() % (DIR_KINDS);
        switch (temp_dir)
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
            next_x = pos_x - GRID_SIZE;
            break;
        default:
            next_y = pos_y - GRID_SIZE;
            break;
        }
        cur_tempo = 0;
    }else {
        move_status = stay;
    }
}

    

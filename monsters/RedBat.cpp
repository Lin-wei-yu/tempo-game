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

void RedBat::move() {
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
        cur_dir = tmp_dir;
    }
    move_status = stay;
    body_status = healthy;
}
void RedBat::early_move(){
    cur_tempo ++;
    if (cur_tempo == tempo) {
        body_status = healthy;
        move_status = leave;
        int temp_dir = rand() % (DIR_KINDS);
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
            next_x = pos_x - GRID_WIDTH;
            break;
        default:
            next_y = pos_y - GRID_HEIGHT;
            break;
        }
        cur_tempo = 0;
    }else {
        move_status = stay;
    }
}

    

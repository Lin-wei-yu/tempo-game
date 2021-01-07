#include "RedBat.h"

RedBat::RedBat(){
    // blue slime profile 
    img = al_load_bitmap("assets/monster/bat_red.png");
    name = "red_bet";
    tempo = 1;
    num_action = 4;

    // others
    pos_x = 50;
    pos_y = 50;
    hidden = false;
    cur_tempo = 0;
    cur_action = 0;
    cur_dir = NON;
}
RedBat::~RedBat(){}

void RedBat::move() {
    // cur_tempo ++;
    // if (cur_tempo == tempo) {
    //     cur_tempo = 0;
    //     int rand_dir = rand() % (DIR_KINDS);
    //     switch (rand_dir)
    //     {
    //     case UP:
    //         pos_y += GRID_HEIGHT;
    //         break;
    //     case DOWN:
    //         pos_y += GRID_HEIGHT;
    //         break;
    //     case LEFT:
    //         pos_x -= GRID_WIDTH;
    //         break;
    //     case RIGHT:
    //         pos_x += GRID_WIDTH;
    //         break;
    //     default:
    //         break;
    //     }
    // }
}
void RedBat::early_move(){

}

    

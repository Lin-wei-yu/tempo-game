#include "GreenSlime.h"
#include <iostream>
using namespace std;
GreenSlime::GreenSlime(ALLEGRO_BITMAP* img):Monster(img){
    // green slime profile
    name = "green_slime";
    tempo = 1;
    num_action = 4;
    power = 1;
    lives = 1;
    drop_money = 1;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;

}
GreenSlime::~GreenSlime(){}

void GreenSlime::move(){
    // green slime cant move
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
        cur_dir = tmp_dir;
    }
    move_status = stay;
    body_status = healthy;
}

void GreenSlime::early_move(){
    cur_tempo ++;
    if (cur_tempo == tempo) {
        move_status = leave;
        body_status = healthy;
        // walking path
        next_x = pos_x;
        next_y = pos_y;
        cur_tempo = 0;
    }else {
        move_status = stay;
    }
    // printf("green:");
    // printf("%d %d %d %d",pos_x,pos_y,next_x,next_y);
    // printf("\n");

}




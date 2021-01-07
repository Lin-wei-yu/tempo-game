#include "GreenSlime.h"
#include <iostream>
using namespace std;
GreenSlime::GreenSlime(): Monster(){
    // green slime profile
    img = al_load_bitmap("assets/monster/slime_green.png");
    name = "green_slime";
    tempo = 1;
    num_action = 4;
    power = 1;
    
}
GreenSlime::~GreenSlime(){}

void GreenSlime::move(){
    // green slime cant move
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
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
    printf("green:");
    printf("%d %d %d %d",pos_x,pos_y,next_x,next_y);
    printf("\n");

}




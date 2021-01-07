#include "BlueSlime.h"

BlueSlime::BlueSlime():Monster(){
    // blue slime profile 
    img = al_load_bitmap("assets/monster/slime_blue.png");
    name = "blue_slime";
    tempo = 2;
    num_action = 8;
    power = 1;
}
BlueSlime::~BlueSlime(){}

void BlueSlime::move() {
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
        cur_dir = temp_dir;
    }
    move_status = stay;
    body_status = healthy;
}
void BlueSlime::early_move(){
    cur_tempo++;
    if (cur_tempo == tempo){
        body_status = healthy;
        move_status = leave;
        // walk path
        switch (cur_dir)
        {
        case UP:
            temp_dir = DOWN;
            next_y = pos_y - GRID_HEIGHT;
            break;
        case DOWN:
            temp_dir = UP;
            next_y = pos_y + GRID_HEIGHT;
            break;
        default:
            temp_dir = DOWN;
            next_y = pos_y - GRID_HEIGHT;
            break;
        }
        cur_tempo = 0;
    }else {
        move_status = stay;
    }

    // printf("blue:");
    // printf("%d %d %d %d",pos_x,pos_y,next_x,next_y);
    // printf("\n");

}

#include "BlueSlime.h"

BlueSlime::BlueSlime(ALLEGRO_BITMAP* img):Monster(img){
    // blue slime profile 
    name = "blue_slime";
    tempo = 2;
    num_action = 8;
    power = 1;
    lives = 2;
    drop_money = 2;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
}
BlueSlime::~BlueSlime(){}

void BlueSlime::move() {
    if (move_status == leave && body_status == healthy){
        pos_x = next_x;
        pos_y = next_y;
        cur_dir = tmp_dir;
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
            tmp_dir = DOWN;
            next_y = pos_y - GRID_HEIGHT;
            break;
        case DOWN:
            tmp_dir = UP;
            next_y = pos_y + GRID_HEIGHT;
            break;
        default:
            tmp_dir = DOWN;
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

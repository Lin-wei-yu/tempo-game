#include "BlueSlime.h"

BlueSlime::BlueSlime(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y):Monster(img,heart_imgs,x,y){
    // blue slime profile 
    name = "blue_slime";
    tempo = 2;
    num_action = 8;
    power = 1;
    starting_lives = remaining_lives = 2;
    drop_money = 2;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
}
BlueSlime::~BlueSlime(){}

void BlueSlime::early_move(int character_pos_x, int character_pos_y){
    cur_tempo++;
    if (cur_tempo == tempo){
        body_status = healthy;
        move_status = leave;
        // walk path
        switch (cur_dir)
        {
        case UP:
            tmp_dir = DOWN;
            next_x = pos_x;
            next_y = pos_y - GRID_SIZE;
            break;
        case DOWN:
            tmp_dir = UP;
            next_x = pos_x;
            next_y = pos_y + GRID_SIZE;
            break;
        default:
            tmp_dir = DOWN;
            next_x = pos_x;
            next_y = pos_y - GRID_SIZE;
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

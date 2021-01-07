#include "MainCharacter.h"
MainCharacter::MainCharacter(const char* path){
    img = al_load_bitmap(path);
    pos_x = 0;
    pos_y = 0;
}
MainCharacter::~MainCharacter(){}

void MainCharacter::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    al_draw_scaled_bitmap(img, 0, 0, w/2, h/2, pos_x, pos_y - CHARACTER_OFFSET, w/2, h/2, 0);
}
void MainCharacter::move(int dir){
    switch (dir)
    {
        case UP:
            pos_y -= GRID_SIZE;
            break;
        case DOWN:
            pos_y += GRID_SIZE;
            break;
        case LEFT:
            pos_x -= GRID_SIZE;
            break;
        case RIGHT:
            pos_x += GRID_SIZE;
            break;
        default:
            break;
    }
}
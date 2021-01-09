#include "Block.h"

Block::Block(int x, int y, BlockType type, ALLEGRO_BITMAP* img) {
    pos_x = x;
    pos_y = y;
    this->type = type;
    this->img = img; 
    switch(type){
        case BACKGROUND:
        case ROAD:
        case DOOR:
            level = 0;
            break;
        case WALL:
        case SHOP:
        case GOAL:
            level = 100;
            break;
        case BREAKABLE_ONE:
            level = 1;
            break;
        case BREAKABLE_TWO:
            level = 2;
            break;
        default:
            break;

    }
}

void Block::draw() {
    if(type != BlockType::BACKGROUND) {
        if(type != BlockType::DOOR) {
            al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
        }
        else { // if door, put floor first then put door
            al_draw_scaled_bitmap(al_load_bitmap("assets/block/floor1.png"), 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
            al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
        }
    }
}
int Block::get_level(){
    return level;
}
#include "Block.h"

Block::Block(int x, int y, BlockType type, ALLEGRO_BITMAP* img) {
    pos_x = x;
    pos_y = y;
    this->type = type;
    this->img = img; 
    
}

void Block::draw() {
    if(type == BlockType::WALL || type == BlockType::SHOP) {
        al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
    }
    else if(type == BlockType::FLOOR_ONE || type == BlockType::FLOOR_TWO) {
        al_draw_scaled_bitmap(img, 0, 0, GRID_SIZE, GRID_SIZE, pos_x, pos_y, GRID_SIZE, GRID_SIZE, 0);
    }
}
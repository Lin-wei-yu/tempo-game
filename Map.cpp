#include "Map.h"
#include <iostream>
Map::Map(){
    for(int i = 0; i < NUM_OF_BLOCK_TYPE; i++) {
        block_vec.push_back(NULL);
    }
    block_vec[BlockType::FLOOR_ONE] = al_load_bitmap("assets/block/floor1.png");
    block_vec[BlockType::FLOOR_TWO] = al_load_bitmap("assets/block/floor2.png");
    block_vec[BlockType::WALL] = al_load_bitmap("assets/block/end_of_world.png");
    block_vec[BlockType::SHOP] = al_load_bitmap("assets/block/wall_shop_crypt.png");
    // floor
    for(int width_iter = 0; width_iter < NUM_OF_WIDTH; width_iter++) {
        for(int height_iter = 0; height_iter < NUM_OF_HEIGHT; height_iter++) {
            if((width_iter + height_iter) % 2 == 0) {
                floors.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter, BlockType::FLOOR_ONE, block_vec[BlockType::FLOOR_ONE]));
                map_type[height_iter][width_iter] = BlockType::FLOOR_ONE;
            }
            else {
                floors.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter, BlockType::FLOOR_TWO, block_vec[BlockType::FLOOR_TWO]));
                map_type[height_iter][width_iter] = BlockType::FLOOR_TWO;
            }
        }
    }
    // wall
    for(int width_iter = 0; width_iter < NUM_OF_WIDTH; width_iter++) {
        for(int height_iter = 0; height_iter < NUM_OF_HEIGHT; height_iter++) {
            if(height_iter == 0 || height_iter == NUM_OF_HEIGHT - 1) {
                blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, BlockType::WALL, block_vec[BlockType::WALL]));
                map_type[height_iter][width_iter] = BlockType::WALL;
            }
            else if(width_iter == 0 || width_iter == NUM_OF_WIDTH - 1) {
                blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, BlockType::WALL, block_vec[BlockType::WALL]));
                map_type[height_iter][width_iter] = BlockType::WALL;
            }
        }
    }
    // shop
    for(int width_iter = 10; width_iter < 20; width_iter++) {
        for(int height_iter = 10; height_iter < 20; height_iter++) {
            if(height_iter == 10 || height_iter == 20 - 1) {
                blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, BlockType::SHOP, block_vec[BlockType::SHOP]));
                map_type[height_iter][width_iter] = BlockType::SHOP;
            }
            else if(width_iter == 10 || width_iter == 20 - 1) {
                blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, BlockType::SHOP, block_vec[BlockType::SHOP]));
                map_type[height_iter][width_iter] = BlockType::SHOP;
            }
        }
    }
}
Map::~Map(){

}

void Map::draw_floor(){
    for (auto f: floors){
        f.draw();
    }
}

void Map::draw_block(){
    for (auto b: blocks){
        b.draw();
    }
}

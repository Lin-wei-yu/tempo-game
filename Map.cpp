#include "Map.h"
#include <iostream>
Map::Map(){
    for(int i = 0; i < NUM_OF_BLOCK_TYPE; i++) {
        block_vec.push_back(NULL);
    }
    block_vec[BlockType::BACKGROUND] = al_load_bitmap("assets/block/floor2.png");
    block_vec[BlockType::WALL] = al_load_bitmap("assets/block/zone4_wall_catacomb_B.png");
    block_vec[BlockType::ROAD] = al_load_bitmap("assets/block/boss_floor_A.png");
    block_vec[BlockType::BREAKABLE_ONE] = al_load_bitmap("assets/block/wall_dirt_crypt_diamond2.png");
    block_vec[BlockType::SHOP] = al_load_bitmap("assets/block/wall_shop_crypt.png");
    block_vec[BlockType::DOOR] = al_load_bitmap("assets/block/door_front.png");
    block_vec[BlockType::BREAKABLE_TWO] = al_load_bitmap("assets/block/wall_dirt_zone2_diamond1.png");
    block_vec[BlockType::GOAL] = al_load_bitmap("assets/block/stairs.png");

    ifstream input_file;
    string s;
    int width_iter = 0, height_iter = 0;
    input_file.open("map/map.txt");
    while(getline(input_file, s)) {
        // std::cout << s << std::endl;
        width_iter = 0;
        for(auto symbol: s) {
            if((BlockType)(symbol - '0') == BlockType::ROAD || (BlockType)(symbol - '0') == BlockType::GOAL) {
                blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter, (BlockType)(symbol - '0'), block_vec[(BlockType)(symbol-'0')]));
            }
            else {
                blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, (BlockType)(symbol - '0'), block_vec[(BlockType)(symbol-'0')]));
            }
            map_type[height_iter][width_iter] = (BlockType)(symbol - '0');
            width_iter++;
        }
        height_iter++;
    }
    input_file.close();
}
Map::~Map(){

}

void Map::draw(){
    for (auto b: blocks){
        b.draw();
    }
}
void Map::pass_beat() {
    for(auto& b: blocks) {
        b.pass_beat();
    }
}
Block Map::get_block(int x, int y) {
    return blocks[y * 60 + x];
}
void Map::delete_wall(int x, int y) {
    blocks[y * 60 + x].delete_wall();
    map_type[y][x] = BlockType::ROAD;
} 


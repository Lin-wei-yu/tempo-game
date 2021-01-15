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
    block_vec[BlockType::SHOP_FLAG] = al_load_bitmap("assets/block/TEMP_shop_floor.png");
    ALLEGRO_BITMAP* torch_in_wall = al_load_bitmap("assets/block/wall_torch.png");
    ifstream input_block_type;
    ifstream input_torch;
    bool have_torch[WINDOW_HEIGHT][WINDOW_WIDTH];
    string s;

    // input torch
    int width_iter = 0, height_iter = 0;
    input_torch.open("map/torch.txt");
    while(getline(input_torch, s)) {
        width_iter = 0;
        for(auto symbol: s) {
            if((symbol - '0') == 8) have_torch[height_iter][width_iter] = true;
            else have_torch[height_iter][width_iter] = false;
            width_iter++;
        }
        height_iter++;
    }
    // input block type
    width_iter = 0, height_iter = 0;
    input_block_type.open("map/map.txt");
    while(getline(input_block_type, s)) {
        // std::cout << s << std::endl;
        width_iter = 0;
        for(auto symbol: s) {
            if((BlockType)(symbol - '0') == BlockType::ROAD || (BlockType)(symbol - '0') == BlockType::GOAL || (BlockType)(symbol - '0') == BlockType::SHOP_FLAG) {
                // blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter, (BlockType)(symbol - '0'), block_vec[(BlockType)(symbol-'0')], torch_in_wall, have_torch[height_iter][width_iter]));
                blocks[height_iter][width_iter] = Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter, (BlockType)(symbol - '0'), block_vec[(BlockType)(symbol-'0')], torch_in_wall, have_torch[height_iter][width_iter]);
            }
            else {
                // blocks.push_back(Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, (BlockType)(symbol - '0'), block_vec[(BlockType)(symbol-'0')], torch_in_wall, have_torch[height_iter][width_iter]));
                blocks[height_iter][width_iter] = Block(GRID_SIZE * width_iter, GRID_SIZE * height_iter - GRID_OFFSET, (BlockType)(symbol - '0'), block_vec[(BlockType)(symbol-'0')], torch_in_wall, have_torch[height_iter][width_iter]);
            }
            map_type[height_iter][width_iter] = (BlockType)(symbol - '0');
            width_iter++;
        }
        height_iter++;
    }
    input_block_type.close();
}
Map::~Map(){

}

void Map::draw_block(int character_x, int character_y){

    // reset vision variable
    for(int height_iter = 0; height_iter < WINDOW_HEIGHT / GRID_SIZE; height_iter++) {
        for(int width_iter = 0; width_iter < WINDOW_WIDTH / GRID_SIZE; width_iter++) {
            blocks[height_iter][width_iter].set_vision(false);
        }
    }

    for(int height_iter = 0; height_iter < WINDOW_HEIGHT / GRID_SIZE; height_iter++) {
        for(int width_iter = 0; width_iter < WINDOW_WIDTH / GRID_SIZE; width_iter++) {
            if(abs(width_iter - character_x) <= 3 && abs(height_iter - character_y) <= 3) {
                blocks[height_iter][width_iter].set_vision(true);
            }
        }
    }
    for(int i = 1; i <= 3; i++) {
        for(int height_iter = 0; height_iter < WINDOW_HEIGHT / GRID_SIZE; height_iter++) {
            for(int width_iter = 0; width_iter < WINDOW_WIDTH / GRID_SIZE; width_iter++) {
                if(abs(width_iter - character_x) <= i && abs(height_iter - character_y) <= i) {
                    if(width_iter == character_x || height_iter == character_y) {
                        if(width_iter == character_x) {
                            if(height_iter < character_y) {
                                if((blocks[height_iter+1][width_iter].get_type() != BlockType::ROAD && blocks[height_iter+1][width_iter].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter+1][width_iter].get_vision() == false) {
                                    blocks[height_iter][width_iter].set_vision(false);
                                }
                            } 
                            else if(height_iter > character_y) {
                                if((blocks[height_iter-1][width_iter].get_type() != BlockType::ROAD && blocks[height_iter-1][width_iter].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter-1][width_iter].get_vision() == false) {
                                    blocks[height_iter][width_iter].set_vision(false);
                                }
                            }
                        }
                        else if(height_iter == character_y) {
                            if(width_iter < character_x) {
                                if((blocks[height_iter][width_iter+1].get_type() != BlockType::ROAD && blocks[height_iter][width_iter+1].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter][width_iter+1].get_vision() == false) {
                                    blocks[height_iter][width_iter].set_vision(false);
                                }
                            } 
                            else if(width_iter > character_x) {
                                if((blocks[height_iter][width_iter-1].get_type() != BlockType::ROAD && blocks[height_iter][width_iter-1].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter][width_iter-1].get_vision() == false) {
                                    blocks[height_iter][width_iter].set_vision(false);
                                }
                            }
                        }
                    }
                    else if(width_iter < character_x && height_iter < character_y) {
                        if(((blocks[height_iter+1][width_iter+1].get_type() != BlockType::ROAD && blocks[height_iter+1][width_iter+1].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter+1][width_iter+1].get_vision() == false)
                        || ((blocks[height_iter+1][width_iter].get_type() != BlockType::ROAD && blocks[height_iter+1][width_iter].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter+1][width_iter].get_vision() == false)) {
                            blocks[height_iter][width_iter].set_vision(false);
                        }
                    }
                    else if(width_iter < character_x && height_iter > character_y) {
                        if(((blocks[height_iter-1][width_iter+1].get_type() != BlockType::ROAD && blocks[height_iter-1][width_iter+1].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter-1][width_iter+1].get_vision() == false)
                        || ((blocks[height_iter-1][width_iter].get_type() != BlockType::ROAD && blocks[height_iter-1][width_iter].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter-1][width_iter].get_vision() == false)) {
                            blocks[height_iter][width_iter].set_vision(false);
                        }
                    }
                    else if(width_iter > character_x && height_iter < character_y) {
                        if(((blocks[height_iter+1][width_iter-1].get_type() != BlockType::ROAD && blocks[height_iter+1][width_iter-1].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter+1][width_iter-1].get_vision() == false)
                        || ((blocks[height_iter+1][width_iter].get_type() != BlockType::ROAD && blocks[height_iter+1][width_iter].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter+1][width_iter].get_vision() == false)) {
                            blocks[height_iter][width_iter].set_vision(false);
                        }
                    }
                    else if(width_iter > character_x && height_iter > character_y) {
                        if(((blocks[height_iter-1][width_iter-1].get_type() != BlockType::ROAD && blocks[height_iter-1][width_iter-1].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter-1][width_iter-1].get_vision() == false)
                        || ((blocks[height_iter-1][width_iter].get_type() != BlockType::ROAD && blocks[height_iter-1][width_iter].get_type() != BlockType::SHOP_FLAG) || blocks[height_iter-1][width_iter].get_vision() == false)) {
                            blocks[height_iter][width_iter].set_vision(false);
                        }
                    }
                }
            }
        }
    }
    // set vision true in 3 * 3 range
    for(int height_iter = -1; height_iter <= 1; height_iter++) {
        for(int width_iter = -1; width_iter <= 1; width_iter++) {
            blocks[character_y + height_iter][character_x + width_iter].set_vision(true);
        }
    }
    // draw block
    for(int height_iter = 0; height_iter < WINDOW_HEIGHT / GRID_SIZE; height_iter++) {
        for(int width_iter = 0; width_iter < WINDOW_WIDTH / GRID_SIZE; width_iter++) {
            blocks[height_iter][width_iter].draw_block(character_x, character_y);
        }
    }
    // draw shovel
    for(int height_iter = 0; height_iter < WINDOW_HEIGHT / GRID_SIZE; height_iter++) {
        for(int width_iter = 0; width_iter < WINDOW_WIDTH / GRID_SIZE; width_iter++) {
            blocks[height_iter][width_iter].draw_shovel();
        }
    }
}
void Map::pass_beat() {
    for(int height_iter = 0; height_iter < WINDOW_HEIGHT / GRID_SIZE; height_iter++) {
        for(int width_iter = 0; width_iter < WINDOW_WIDTH / GRID_SIZE; width_iter++) {
            blocks[height_iter][width_iter].pass_beat();
        }
    }
}
Block Map::get_block(int x, int y) {
    return blocks[y][x];
}
void Map::delete_wall(int x, int y, ALLEGRO_BITMAP* shovel_img) {
    blocks[y][x].delete_wall(shovel_img);
    map_type[y][x] = BlockType::ROAD;
} 


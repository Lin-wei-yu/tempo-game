#include "Map.h"
#include <iostream>
Map::Map(){
    basic = al_load_bitmap("assets/block/wall_shop_crypt.png");

    blocks.push_back({0,0});
    blocks.push_back({0,0 + 24});
    blocks.push_back({0,0 + 24*2});
}
Map::~Map(){

}

void Map::draw(){
    for (auto b: blocks){
        al_draw_bitmap(basic, b.first, b.second, 0);
    }
}

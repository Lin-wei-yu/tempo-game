#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define NUM_OF_BLOCK_TYPE 9

#include <allegro5/allegro.h>
#include <vector>
#include "Object.h"
#include "global.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Block.h"
using namespace std;

class Map{
public:
    Map();
    ~Map();

    void draw_block(int character_x, int character_y);
    void draw(){};
    void pass_beat();
    Block get_block(int x, int y);
    void delete_wall(int x, int y, ALLEGRO_BITMAP* shovel_img);
    BlockType map_type[NUM_OF_HEIGHT][NUM_OF_WIDTH];
private:
    Block blocks[WINDOW_HEIGHT/GRID_SIZE][WINDOW_WIDTH/GRID_SIZE];
    
    vector<ALLEGRO_BITMAP*> block_img_vec;
};


#endif
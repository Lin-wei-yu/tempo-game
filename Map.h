#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#define NUM_OF_BLOCK_TYPE 9

#include <allegro5/allegro.h>
#include <vector>
#include "Object.h"
#include "global.h"
#include <fstream>
#include <string>
#include "Block.h"
using namespace std;

class Map{
public:
    Map();
    ~Map();

    void draw();
    void pass_beat();
    Block get_block(int x, int y);
    void delete_wall(int x, int y);
    BlockType map_type[NUM_OF_HEIGHT][NUM_OF_WIDTH];
private:
    vector<Block> blocks;
    vector<ALLEGRO_BITMAP*> block_vec;
};


#endif
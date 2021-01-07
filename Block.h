#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <allegro5/allegro.h>
#include "Object.h"
#include "global.h"
enum BlockType {
    WALL, SHOP, FLOOR_ONE, FLOOR_TWO
};


class Block:public Object{
public:
    Block(int, int, BlockType, ALLEGRO_BITMAP*);
    ~Block(){};

    void draw();
private:
    BlockType type;
};


#endif
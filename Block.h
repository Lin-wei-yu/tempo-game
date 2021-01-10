#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <allegro5/allegro.h>
#include "Object.h"
#include "global.h"
enum BlockType {
    BACKGROUND, WALL, ROAD, BREAKABLE_ONE, SHOP, DOOR, BREAKABLE_TWO, GOAL
};


class Block:public Object{
public:
    Block(int, int, BlockType, ALLEGRO_BITMAP*);
    ~Block(){};
    void pass_beat();
    void change_animation();
    void draw();
    int get_level();
private:
    BlockType type;
    int level;
    int beat_of_change;
    int beat_cnt;
    bool is_odd;
    bool beat;
};


#endif
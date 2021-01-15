#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <allegro5/allegro.h>
#include "Object.h"
#include "global.h"
enum BlockType {
    BACKGROUND, WALL, ROAD, BREAKABLE_ONE, SHOP, DOOR, BREAKABLE_TWO, GOAL, SHOP_FLAG
};


class Block:public Object{
public:
    Block(){};
    Block(int, int, BlockType, ALLEGRO_BITMAP*, ALLEGRO_BITMAP*, bool);
    ~Block(){};
    void pass_beat();
    void change_animation();
    void draw_block(int, int);
    void draw_shovel();
    void draw(){};
    void set_vision(bool in_vision) { this->in_vision = in_vision; };
    bool get_vision() { return in_vision; };
    BlockType get_type() { return type; };
    void delete_wall(ALLEGRO_BITMAP* shovel_img);
    int get_level();
private:
    BlockType type;
    int level;
    int beat_of_change;
    int beat_cnt;
    bool beat;
    int tempo;
    int num_action = 4;
    int cur_action;
    bool have_torch = false;
    bool is_shovel = false;
    bool is_visited = false;
    bool in_vision;
    ALLEGRO_BITMAP* shovel_img;
    ALLEGRO_BITMAP* torch_in_wall;
};


#endif
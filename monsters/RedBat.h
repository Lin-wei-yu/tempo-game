#ifndef REDBAT_H_INCLUDED
#define REDBAT_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <string>
class RedBat:public Monster{
public: 
    RedBat(ALLEGRO_BITMAP* img);
    ~RedBat();
    void early_move(int character_pos_x, int character_pos_y) override; 
    void get_reward() override{};
};
#endif
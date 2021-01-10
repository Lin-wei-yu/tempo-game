#ifndef BLACKSKELETON_H_INCLUDED
#define BLACKSKELETON_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <cmath>
#include <iostream>
using namespace std;
class BlackSkeleton:public Monster{
public: 
    BlackSkeleton(ALLEGRO_BITMAP* img);
    ~BlackSkeleton();
    void early_move(int character_pos_x, int character_pos_y) override;
    void draw() override;
    void get_reward() override{};
    private:
    int sense_range;
};
#endif
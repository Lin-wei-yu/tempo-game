#ifndef SKELETON_H_INCLUDED
#define SKELETON_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <cmath>
#include <iostream>
using namespace std;
class Skeleton:public Monster{
public: 
    Skeleton(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs);
    ~Skeleton();
    void early_move(int character_pos_x, int character_pos_y) override;
    void draw() override;
    void get_reward() override{};
private:
    int sense_range;
};
#endif
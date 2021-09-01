#ifndef STONEGOLEM_H_INCLUDED
#define STONEGOLEM_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <cmath>
#include <iostream>
using namespace std;
class StoneGolem:public Monster{
public: 
    StoneGolem(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y);
    ~StoneGolem();
    void early_move(int character_pos_x, int character_pos_y) override;
    void get_reward() override{};
private:
    int sense_range;
};
#endif
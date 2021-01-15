#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <string>
#include <iostream>
class Zombie:public Monster{
public: 
    Zombie(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y);
    ~Zombie();
    void early_move(int character_pos_x, int character_pos_y) override; 
    void get_reward() override{};
    void draw() override;
private:
};
#endif
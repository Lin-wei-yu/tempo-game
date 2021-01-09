#ifndef ZOMBIE_H_INCLUDED
#define ZOMBIE_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <string>
#include <iostream>
class Zombie:public Monster{
public: 
    Zombie(ALLEGRO_BITMAP* img);
    ~Zombie();
    void move() override;   
    void early_move() override; 
    void get_reward() override{};
    void draw() override;
private:
};
#endif
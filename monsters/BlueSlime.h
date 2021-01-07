#ifndef BLUESLIME_H_INCLUDED
#define BLUESLIME_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <string>
class BlueSlime:public Monster{
public: 
    BlueSlime();
    ~BlueSlime();
    void move();
    void early_move();
    void get_reward(){};
};
#endif
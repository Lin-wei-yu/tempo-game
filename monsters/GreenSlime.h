#ifndef GREENSLIME_H_INCLUDED
#define GREENSLIME_H_INCLUDED
#include "../Monster.h"
#include <string>
class GreenSlime:public Monster{
public: 
    GreenSlime();
    ~GreenSlime();
    void move();
    void early_move();
    void get_reward(){};
};
#endif
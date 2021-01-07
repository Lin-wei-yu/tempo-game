#ifndef REDBAT_H_INCLUDED
#define REDBAT_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include "../MainCharacter.h"
#include <string>
class RedBat:public Monster{
public: 
    RedBat();
    ~RedBat();
    void move();   
    void early_move(); 
    void get_reward(){};

};
#endif
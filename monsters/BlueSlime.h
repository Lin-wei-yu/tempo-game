#ifndef BLUESLIME_H_INCLUDED
#define BLUESLIME_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <string>
class BlueSlime:public Monster{
public: 
    BlueSlime(ALLEGRO_BITMAP* img);
    ~BlueSlime();
    void move() override;
    void early_move() override;
    void get_reward() override{};
};
#endif
#ifndef GREENSLIME_H_INCLUDED
#define GREENSLIME_H_INCLUDED
#include "../Monster.h"
#include <allegro5/allegro5.h>
#include <string>
class GreenSlime:public Monster{
public: 
    GreenSlime(ALLEGRO_BITMAP* img);
    ~GreenSlime();
    void move() override;
    void early_move() override;
    void get_reward() override{};
};
#endif
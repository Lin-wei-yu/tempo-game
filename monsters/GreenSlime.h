#ifndef GREENSLIME_H_INCLUDED
#define GREENSLIME_H_INCLUDED
#include "../Monster.h"
#include <allegro5/allegro5.h>
#include <string>
class GreenSlime:public Monster{
public: 
    GreenSlime(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs);
    ~GreenSlime();
    void early_move(int character_pos_x, int character_pos_y) override;
    void get_reward() override{};
};
#endif
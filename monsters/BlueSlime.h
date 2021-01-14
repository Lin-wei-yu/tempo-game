#ifndef BLUESLIME_H_INCLUDED
#define BLUESLIME_H_INCLUDED
#include "../Monster.h"
#include "../global.h"
#include <string>
class BlueSlime:public Monster{
public: 
    BlueSlime(ALLEGRO_BITMAP* img, map<string, ALLEGRO_BITMAP*>& heart_imgs, int x, int y);
    ~BlueSlime();
    void early_move(int character_pos_x, int character_pos_y) override;
    void get_reward() override{};
};
#endif
#ifndef ADVANCEDSHOVEL_H_INCLUDED
#define ADVANCEDSHOVEL_H_INCLUDED
#include "../Item.h"

class AdvancedShovel: public Item{
public:
    AdvancedShovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, int x, int y, int value, vector<ALLEGRO_BITMAP*> number_imgs);
    AdvancedShovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img );
    ~AdvancedShovel(){};
private:
};

#endif
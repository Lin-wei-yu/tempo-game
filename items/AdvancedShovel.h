#ifndef ADVANCEDSHOVEL_H_INCLUDED
#define ADVANCEDSHOVEL_H_INCLUDED
#include "../Item.h"

class AdvancedShovel: public Item{
public:
    AdvancedShovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, int x, int y);
    AdvancedShovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img );
    ~AdvancedShovel(){};
private:
};

#endif
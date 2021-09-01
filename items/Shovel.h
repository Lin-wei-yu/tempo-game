#ifndef SHOVEL_H_INCLUDED
#define SHOVEL_H_INCLUDED
#include "../Item.h"

class Shovel: public Item{
public:
    Shovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, vector<ALLEGRO_BITMAP*> number_imgs, int x, int y);
    Shovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img );
    ~Shovel(){};
private:
};

#endif
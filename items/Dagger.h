#ifndef DAGGER_H_INCLUDED
#define DAGGER_H_INCLUDED
#include "../Item.h"

class Dagger: public Item{
public:
    Dagger(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, vector<ALLEGRO_BITMAP*> number_imgs, int x, int y);
    Dagger(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img );
    ~Dagger(){};
};

#endif
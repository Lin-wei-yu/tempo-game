#ifndef LONGSWORD_H_INCLUDED
#define LONGSWORD_H_INCLUDED
#include "../Item.h"
#include "../Range.h"

class LongSword: public Item{
public:
    LongSword(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img, int x, int y, int value, vector<ALLEGRO_BITMAP*> number_imgs);
    LongSword(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img );
    ~LongSword();

private:
};

#endif
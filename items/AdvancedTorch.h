#ifndef ADVANCEDTORCH_H_INCLUDED
#define ADVANCEDTORCH_H_INCLUDED
#include "../Item.h"

class AdvancedTorch: public Item{
public:
    AdvancedTorch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, int x, int y);
    AdvancedTorch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img);
    ~AdvancedTorch(){};
private:
};
#endif
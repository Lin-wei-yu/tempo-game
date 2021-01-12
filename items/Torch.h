#ifndef TORCH_H_INCLUDED
#define TORCH_H_INCLUDED
#include "../Item.h"

class Torch: public Item{
public:
    Torch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, int x, int y, int value, vector<ALLEGRO_BITMAP*> number_imgs);
    Torch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img );
    ~Torch(){};
private:
};
#endif
#ifndef TORCH_H_INCLUDED
#define TORCH_H_INCLUDED
#include "../Item.h"

class Torch: public Item{
public:
    Torch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, vector<ALLEGRO_BITMAP*> number_imgs, int x, int y);
    Torch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img );
    ~Torch(){};
private:
};
#endif
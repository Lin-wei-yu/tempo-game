#include "AdvancedShovel.h"

AdvancedShovel::AdvancedShovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, vector<ALLEGRO_BITMAP*> number_imgs, int x, int y):Item(img, slot_img){
    //
    pos_x = x;
    pos_y = y;
    item_type = shovel;
    item_level = 2;
    num_animation = 1;
    this->value = 10;
    this->number_imgs = number_imgs;
    // 
}

AdvancedShovel::AdvancedShovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ):Item(img, slot_img){
    //
    item_type = shovel;
    item_level = 2;
    num_animation = 1;

    //
}
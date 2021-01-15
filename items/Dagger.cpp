#include "Dagger.h"
Dagger::Dagger(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img,  vector<ALLEGRO_BITMAP*> number_imgs, int x, int y):Item(img, slot_img){
    //
    pos_x = x;
    pos_y = y;
    item_type = attack_tool;
    item_level = 1;
    num_animation = 1;
    this->value = 0;
    this->number_imgs = number_imgs;
    //
    power = 1;

}

Dagger::Dagger(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ):Item(img, slot_img){
    //
    item_type = attack_tool;
    item_level = 1;
    num_animation = 1;
    //
    power = 1;

}

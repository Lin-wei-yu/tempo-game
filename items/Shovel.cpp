#include "Shovel.h"

Shovel::Shovel(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ):Item(img, slot_img){
    //
    item_type = shovel;
    item_level = 1;
    num_animation = 1;

    //
}

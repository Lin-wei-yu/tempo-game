#include "AdvancedTorch.h"

AdvancedTorch::AdvancedTorch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, int x, int y):Item(img, slot_img){
    //
    pos_x = x;
    pos_y = y;
    item_type = torch;
    item_level = 2;
    num_animation = 1;
    //   
}

AdvancedTorch::AdvancedTorch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ):Item(img, slot_img){
    //
    item_type = torch;
    item_level = 2;
    num_animation = 1;
    //
}
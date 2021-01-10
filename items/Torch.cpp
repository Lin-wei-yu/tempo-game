#include "Torch.h"

Torch::Torch(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ):Item(img, slot_img){
    //
    item_type = torch;
    item_level = 1;
    num_animation = 1;
    //
}

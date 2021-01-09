#include "Dagger.h"
Dagger::Dagger(ALLEGRO_BITMAP* img):Item(img){
    //
    item_type = attack;
    //
    power = 1;
}
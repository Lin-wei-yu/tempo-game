#include "Item.h"

Item::Item(ALLEGRO_BITMAP* img){
    this -> img = img;
}
void Item::show(int x, int y){
    al_draw_bitmap(img, x, y, 0);
}
ItemType Item::get_type(){
    return item_type;
}

#include "Item.h"

Item::Item(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ){
    this -> img = img;
    this -> slot_img = slot_img;
}
void Item::draw(){
    al_draw_bitmap(img, pos_x, pos_y, 0);
}
void Item::show(int x, int y){
    int sw = al_get_bitmap_width(img)/num_animation;
    int sh = al_get_bitmap_height(img)/2;  
    int offset_x = 5;
    int offset_y = 5;
    al_draw_scaled_bitmap(img, 0, 0, sw, sh, x+offset_x, y+offset_y, sw, sh, 0);
    al_draw_bitmap(slot_img, x, y, 0);
}
ItemType Item::get_type(){
    return item_type;
}
int Item::get_level(){
    return item_level;
}

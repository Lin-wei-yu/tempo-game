#include "Reward.h"
Reward::Reward(){
    hidden = false;
}
void Reward::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    
    if (hidden == false){
        al_draw_scaled_bitmap(img, 0, 0, w, h/2, pos_x, pos_y, w, h/2, 0);
    }else {
        al_draw_scaled_bitmap(img, 0, h/2, w, h/2, pos_x, pos_y, w, h/2, 0);
    }
}
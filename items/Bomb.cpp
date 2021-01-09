#include "Bomb.h"
Bomb::Bomb(ALLEGRO_BITMAP* img){
    this -> img = img;
    start_count = false;
    beat_cnt = 0;
}
void Bomb::release(){
    start_count = true;
}
void Bomb::draw(){
    int w = al_get_bitmap_width(img);
    if (start_count){
        // al_draw_scaled_bitmap(img, 0);
    }
}
void Bomb::pass_beat(){
    if (start_count){
        beat_cnt ++;
    }
}
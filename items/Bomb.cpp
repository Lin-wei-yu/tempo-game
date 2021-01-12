#include "Bomb.h"

Bomb::Bomb(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img, int x, int y, int value, vector<ALLEGRO_BITMAP*> number_imgs):Item(img, slot_img){
    //
    pos_x = x;
    pos_y = y;
    item_type = bomb;
    item_level = 1;
    num_animation = 5;
    this->value = value;
    this->number_imgs = number_imgs;
    //
    power = 1;
    using_command = "space";
    start_count = false;
    beat_cnt = 0;
}
Bomb::Bomb(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ):Item(img, slot_img){
    //
    item_type = bomb;
    item_level = 1;
    num_animation = 5;
    //
    power = 1;
    using_command = "space";
    start_count = false;
    beat_cnt = 0;

}
void Bomb::release(){
    start_count = true;
}
void Bomb::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    int sw = (w/num_animation);
    if (start_count){
        al_draw_scaled_bitmap(img, sw*(beat_cnt-1), 0, sw, h, pos_x, pos_y, sw, h, 0);
    }else{
        al_draw_scaled_bitmap(img, 0, 0, sw, h, pos_x, pos_y, sw, h, 0);
    }
}

void Bomb::pass_beat(){
    if (start_count){
        beat_cnt ++;
    }
}

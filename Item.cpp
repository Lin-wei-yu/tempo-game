#include "Item.h"

Item::Item(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img ){
    this -> img = img;
    this -> slot_img = slot_img;
    using_command = "";
    alphabet_img = al_load_bitmap("assets/font/alphabet_white.png");
    is_demaged = false;
}
void Item::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    al_draw_scaled_bitmap(img, 0, 0, w, h/2, pos_x, pos_y, w, h/2, 0);

    // draw coin num
    w = al_get_bitmap_width(number_imgs[0]);
    h = al_get_bitmap_height(number_imgs[0]);
    
    if(value != 0) {
        int gap = 2;
        string coin_str = to_string(value);
        for (int i=0; i<coin_str.size(); i++){
            int num_idx = coin_str[i] - '0';
            al_draw_scaled_bitmap(number_imgs[num_idx], 0, 0, w, h, pos_x+i*(w+gap), pos_y-10, w, h, 0);
        }
    }
}
void Item::show(int x, int y, float enlarge_ratio){
    // draw item.
    float item_w = al_get_bitmap_width(img)/num_animation;
    float item_h = al_get_bitmap_height(img)/2;  
    float offset_x = 5*enlarge_ratio;
    float offset_y = 5*enlarge_ratio;
    al_draw_scaled_bitmap(img, 0, 0, item_w, item_h, x+offset_x, y+offset_y, item_w*enlarge_ratio, item_h*enlarge_ratio, 0);
    // draw slot.
    float slot_w = al_get_bitmap_width(slot_img);
    float slot_h = al_get_bitmap_height(slot_img);
    al_draw_scaled_bitmap(slot_img, 0, 0, slot_w, slot_h, x, y, slot_w*enlarge_ratio, slot_h*enlarge_ratio, 0);
    // draw command.
    offset_y = (slot_h-10)*enlarge_ratio;
    float char_w = al_get_bitmap_width(alphabet_img)/26;
    float char_h = al_get_bitmap_height(alphabet_img);
    int gap = 2;
    if (using_command != ""){
        for (char c : using_command){
            int char_idx = c - 'a';
            al_draw_scaled_bitmap(alphabet_img, char_idx*char_w, 0, char_w, char_h, x+offset_x, y+offset_y, char_w, char_h, 0);
            offset_x = offset_x + char_w + gap;
        }
    }
}
ItemType Item::get_type(){
    return item_type;
}
int Item::get_level(){
    return item_level;
}
float Item::get_power(){
    return power;
}
Range Item::get_range(){
    return range;
}
string Item::get_command(){
    return using_command;
}
void Item::release(int x, int y){
    pos_x = x;
    pos_y = y;
}
bool Item::need_recycle(){
    return is_demaged;
}
bool Item::is_attacking(){
   return false; 
}


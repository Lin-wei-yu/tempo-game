#include "Bomb.h"

Bomb::Bomb(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img, ALLEGRO_BITMAP* explosion_img, int x, int y):Item(img, slot_img){
    //
    pos_x = x;
    pos_y = y;
    item_type = bomb;
    item_level = 1;
    num_animation = 5;
    //
    power = 1;
    using_command = "space";
    start_count = false;
    end_count = false;
    beat_cnt = 0;
    beat_of_change = 2;
    cur_animation = 0;
    this -> explosion_img = explosion_img;
    explode_animation = 8;
    range.build_range(1, 1, 1, 1);
}
Bomb::Bomb(ALLEGRO_BITMAP* img,ALLEGRO_BITMAP* slot_img, ALLEGRO_BITMAP* explosion_img ):Item(img, slot_img){
    //
    item_type = bomb;
    item_level = 1;
    num_animation = 5;
    //
    power = 1;
    using_command = "space";
    start_count = false;
    end_count = false;
    beat_cnt = 0;
    beat_of_change = 2;
    cur_animation = 0;
    this -> explosion_img = explosion_img;
    explode_animation = 8;
    range.build_range(1, 1, 1, 1);

}
void Bomb::release(int x, int y){
    pos_x = x;
    pos_y = y;
    start_count = true;
}
void Bomb::draw(){
    int bomb_w = al_get_bitmap_width(img);
    int bomb_h = al_get_bitmap_height(img);
    int bomb_sw = (bomb_w/num_animation);
    int bomb_sh = bomb_h/2;
    if (start_count && !end_count){
        // exit(0);

        if (cur_animation < num_animation){
            // draw bomb.
            al_draw_scaled_bitmap(img, bomb_sw*(cur_animation), 0, bomb_sw, bomb_sh, pos_x, pos_y, bomb_sw, bomb_sh, 0);
        }else {
            // draw explosion.
            int exp_w = al_get_bitmap_width(explosion_img);
            int exp_h = al_get_bitmap_height(explosion_img);
            int exp_sw = al_get_bitmap_width(explosion_img)/explode_animation;
            int exp_sh = exp_h;
            al_draw_scaled_bitmap(explosion_img, exp_sw*(cur_animation-num_animation), 0, exp_sw, exp_sh, pos_x-(exp_sw/2), pos_y-(exp_sh/2), exp_sw, exp_sh, 0);
            if (cur_animation == num_animation+explode_animation){
                end_count = true;
                is_demaged = true;
            }
        }

    }else if (!start_count){
        al_draw_scaled_bitmap(img, 0, 0, bomb_sw, bomb_sh, pos_x, pos_y, bomb_sw, bomb_sh, 0);
    }
    
}
void Bomb::change_animation(){
    cur_animation ++;
}
void Bomb::pass_beat(){
    if (start_count){
        beat_cnt ++;
        if (beat_cnt == beat_of_change){
            change_animation();
            beat_cnt = 0;
        }
    }
}
bool Bomb::is_attacking(){
    if (start_count && !end_count && cur_animation==num_animation+1) return true;
    else return false;
}



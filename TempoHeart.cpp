#include "TempoHeart.h"

TempoHeart::TempoHeart(){
    img = al_load_bitmap("assets/heart/TEMP_beat_heart.png");
    pos_x = 300;
    pos_y = 200;
    num_animation = 2;
    cur_animation = 0;
    beat_of_change = BEAT_PER_TEMPO / num_animation;
    beat_cnt = 0;
    beat_marker_img = al_load_bitmap("assets/heart/TEMP_beat_marker.png");
    beat_marker_pos = {0, 24, 48, 72, 96};
}
TempoHeart::~TempoHeart(){}

void TempoHeart::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    al_draw_scaled_bitmap(img, (w/2)*cur_animation, 0, w/2, h, pos_x, pos_y, w/2, h, 0);

    int offset = 10;
    for(auto pos : beat_marker_pos){
        al_draw_bitmap(beat_marker_img, offset + pos + beat_cnt*3, 200, 0);
    }
}
void TempoHeart::pass_beat(){
    beat_cnt++;
    if (beat_cnt == beat_of_change){
        change_animation();
        beat_cnt = 0;
    }
}
void TempoHeart::change_animation(){
    cur_animation ++;
    if (cur_animation == num_animation){
        cur_animation = 0;
    }
}
#include "TempoHeart.h"

TempoHeart::TempoHeart(){
    img = al_load_bitmap("assets/heart/TEMP_beat_heart.png");
    pos_x = WINDOW_WIDTH/2;
    pos_y = WINDOW_HEIGHT - 180;

    num_animation = 2;
    cur_animation = 0;
    beat_of_change = BEAT_PER_TEMPO / num_animation;
    beat_cnt = 0;
    beat_marker_img = al_load_bitmap("assets/heart/TEMP_beat_marker.png");

    beat_marker_range = 192;
    for (int i=0; i<4; i++){
        beat_marker_pos.push_back(beat_marker_range*i);
    }
}
TempoHeart::~TempoHeart(){}

void TempoHeart::draw(){
    // draw bumping heart
    int heart_w = al_get_bitmap_width(img)/2;
    int heart_h = al_get_bitmap_width(img);
    int heart_scaled_ratio = 3;
    int offset_x = 12;
    al_draw_scaled_bitmap(img, heart_w*cur_animation, 0, heart_w, heart_h, pos_x-(heart_w*heart_scaled_ratio/2)+offset_x, pos_y, heart_w*heart_scaled_ratio, heart_h*heart_scaled_ratio, 0);
    
    // draw beat marker 
    int marker_w = al_get_bitmap_width(beat_marker_img);
    int marker_h = al_get_bitmap_height(beat_marker_img);
    offset_x = 100;
    int offset_y = 30;
    int range_per_beat = beat_marker_range / BEAT_PER_TEMPO;
    for(auto pos : beat_marker_pos){
        int left_bar_pos = offset_x+pos+(range_per_beat*beat_cnt);
        int right_bar_pos = WINDOW_WIDTH-left_bar_pos;

        int half_heart_w = (heart_w*heart_scaled_ratio)/2;

        if ( left_bar_pos >= (pos_x - half_heart_w)){
            al_draw_scaled_bitmap(beat_marker_img, 0, 0, marker_w, marker_h, pos_x - half_heart_w, pos_y+offset_y, marker_w*3, marker_h*4, 0);
        }else{
            al_draw_scaled_bitmap(beat_marker_img, 0, 0, marker_w, marker_h, left_bar_pos, pos_y+offset_y, marker_w*3, marker_h*4, 0);
        }
        if (right_bar_pos <= pos_x + half_heart_w){
            al_draw_scaled_bitmap(beat_marker_img, 0, 0, marker_w, marker_h, pos_x+half_heart_w, pos_y+offset_y, marker_w*3, marker_h*4, 0);    
        }else {
            al_draw_scaled_bitmap(beat_marker_img, 0, 0, marker_w, marker_h, right_bar_pos, pos_y+offset_y, marker_w*3, marker_h*4, 0);    
        }
    }
}
void TempoHeart::pass_beat(){
    beat_cnt++;
    if (beat_cnt % beat_of_change == 0){
        change_animation();
        if (beat_cnt == BEAT_PER_TEMPO) beat_cnt = 0;
    }
}
void TempoHeart::change_animation(){
    cur_animation ++;
    if (cur_animation == num_animation){
        cur_animation = 0;
    }
}
#ifndef TEMPOHEART_H_INCLUDED
#define TEMPOHEART_H_INCLUDED
#include <allegro5/allegro5.h>
#include <vector>
#include "Object.h"
#include "global.h"
#include <iostream>
using namespace std;
class TempoHeart: public Object{
public:
    TempoHeart(ALLEGRO_BITMAP* heart_img, ALLEGRO_BITMAP* beat_marker_img, ALLEGRO_BITMAP* missed_img);
    ~TempoHeart();
    void change_animation();
    void pass_beat();
    void draw();
    void miss_tempo();
private:
    int num_animation;
    int cur_animation;
    int beat_of_change;
    int beat_cnt;
    int beat_marker_range;
    ALLEGRO_BITMAP* beat_marker_img;
    ALLEGRO_BITMAP* missed_img;
    vector<int> beat_marker_pos;
    bool missed_tempo;
};
#endif
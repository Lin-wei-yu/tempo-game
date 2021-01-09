#ifndef TEMPOHEART_H_INCLUDED
#define TEMPOHEART_H_INCLUDED
#include <allegro5/allegro5.h>
#include "Object.h"
#include "global.h"

class TempoHeart: public Object{
public:
    TempoHeart();
    ~TempoHeart();
    void change_animation();
    void pass_beat();
    void draw();
private:
    int num_animation;
    int cur_animation;
    int beat_of_change;
    int beat_cnt;
};
#endif
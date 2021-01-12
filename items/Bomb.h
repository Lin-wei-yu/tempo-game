#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED
#include "../Item.h"
#include <iostream>
using namespace std;
class Bomb: public Item{
public:
    Bomb(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img, ALLEGRO_BITMAP* explosion_img, int x, int y);
    Bomb(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img, ALLEGRO_BITMAP* explosion_img);
    ~Bomb(){};
    void draw() override;
    void release(int x, int y) override;
    void pass_beat() override;
    void change_animation();
    bool is_attacking() override;
    
private:
    bool start_count;
    bool end_count;
    int beat_cnt;
    int beat_of_change;
    int cur_animation;
    int explode_animation;
    ALLEGRO_BITMAP* explosion_img;
};

#endif
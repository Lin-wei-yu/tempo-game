#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED
#include "../Item.h"

class Bomb: public Item{
public:
    Bomb(ALLEGRO_BITMAP* img);
    ~Bomb(){};
    void draw() override;
    void show(int x, int y) override;
    void release();
    void pass_beat();
private:
    bool start_count;
    int beat_cnt;
    int num_animation;
    int power;
};

#endif
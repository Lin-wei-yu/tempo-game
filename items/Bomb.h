#ifndef BOMB_H_INCLUDED
#define BOMB_H_INCLUDED
#include "../Item.h"

class Bomb: public Item{
public:
    Bomb(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img, int x, int y, int value, vector<ALLEGRO_BITMAP*> number_imgs);
    Bomb(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img );
    ~Bomb(){};
    void draw() override;
    void release();
    void pass_beat();
    
private:
    bool start_count;
    int beat_cnt;
};

#endif
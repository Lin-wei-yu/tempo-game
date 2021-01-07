#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED
#include <allegro5/allegro.h>
#include "global.h"
#include "Object.h"
// typedef enum _MoveStatus{leave, stay} MoveStatus;
class MainCharacter : public Object{
public:
    MainCharacter(const char* path);
    ~MainCharacter();
    void draw();
    void move();
    void early_move();
    bool is_dead();
    // void attack(Monster* monster);
    void attack();
    void be_attacked(int power);
    void change_dir(DIR dir);
    int get_power();
    int get_next_x();
    int get_next_y();
private:
    DIR temp_dir;
    int lives;
    MoveStatus move_status;
    BodyStatus body_status;
    int power;
    int tempo;
    int cur_tempo;
    ALLEGRO_BITMAP* heart_img;
    int num_coin;
    int next_x;
    int next_y;
};
#endif
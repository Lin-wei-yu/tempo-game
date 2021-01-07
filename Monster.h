#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include <allegro5/allegro.h>
#include <string>
#include "Object.h"
#include "global.h"

using namespace std;
// typedef enum _BodyStatus{injured, healthy} BodyStatus;
// typedef enum _MoveStatus {leave, stay} MoveStatus;

class Monster: public Object{
public:
    Monster();
    virtual ~Monster();
    void draw();
    void change_action();
    bool is_dead();
    void attack();
    void be_attacked(int power);
    // void attack(MainCharacter* main_character);
    virtual void move() = 0;
    virtual void early_move() = 0;
    virtual void get_reward() = 0;
    int get_power();
    int get_next_x();
    int get_next_y();

protected:
    // define in sub-class
    string name;
    bool hidden;
    int power;
    int lives;
    int tempo;
    int num_action;
    // define in current class
    DIR cur_dir;
    DIR temp_dir;
    int cur_tempo;
    int cur_action;
    BodyStatus body_status;
    MoveStatus move_status;
    int next_x;
    int next_y;
};

#endif
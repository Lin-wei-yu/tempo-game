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
    Monster(ALLEGRO_BITMAP* img);
    virtual ~Monster();
    virtual void draw();
    void change_action();
    bool is_dead();
    void attack();
    void be_attacked(int power);
    void move();
    virtual void early_move(int character_pos_x, int character_pos_y) = 0;
    virtual void get_reward() = 0;
    float get_power();
    int get_next_x();
    int get_next_y();
    int get_drop_money();
    string get_name(){return name;};
    void change_direction();
    void pass_beat();

protected:
    // define in sub-class
    string name;
    int tempo;
    int num_action;
    float power;
    float lives;
    int drop_money;
    int beat_of_change;
    // define in current class
    DIR cur_dir;
    DIR tmp_dir;
    int cur_tempo;
    int cur_action;
    BodyStatus body_status;
    MoveStatus move_status;
    int next_x;
    int next_y;
    bool hidden;
    int beat_cnt;
    bool jumping;
};

#endif
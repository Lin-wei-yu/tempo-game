#include"Monster.h"

using namespace std;
// monster manual
// static MonsterDOC monster_manual;
Monster::Monster():Object(){
    
    pos_x = (rand()%5 )* 24;
    pos_y = (rand()%5 )* 24;
    hidden = false;
    cur_tempo = 0;
    cur_action = 0;
    cur_dir = NON;
    temp_dir = NON;
    body_status = healthy;
    move_status = stay;
    next_x = pos_x;
    next_y = pos_y;
}
Monster::~Monster(){}
void Monster::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    int sw = w / num_action; 
    int sh = h / 2;

    if (hidden == false){
        al_draw_scaled_bitmap(img, sw*cur_action, 0, sw, sh, pos_x, pos_y, sw, sh, 0);
    }else {
        al_draw_scaled_bitmap(img, sw*cur_action, sh, sw, sh, pos_x, pos_y, sw, sh, 0);
    }
}
void Monster::change_action(){
    cur_action = cur_action + 1;
    if (cur_action == num_action) cur_action = 0;
}
bool Monster::is_dead(){
    return (lives <= 0);
}
void Monster::attack(){
    move_status = stay;
}
void Monster::be_attacked(int power){
    lives = lives - power;
    body_status = injured;
}
int Monster::get_power(){
    return power;
}
int Monster::get_next_x(){
    return next_x;
}
int Monster::get_next_y(){
    return next_y;
}




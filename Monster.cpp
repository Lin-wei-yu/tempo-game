#include"Monster.h"

using namespace std;
// monster manual
// static MonsterDOC monster_manual;
Monster::Monster(ALLEGRO_BITMAP* img,map<string, ALLEGRO_BITMAP*>& heart_imgs):Object(){
    // declare in object.h
    this -> img = img;
    this -> heart_imgs = heart_imgs;
    pos_x = (rand()%5 )* GRID_SIZE + 5 * GRID_SIZE;
    pos_y = (rand()%5 )* GRID_SIZE + 5 * GRID_SIZE;

    // declare in monster.h
    cur_dir = NON;
    tmp_dir = NON;
    cur_tempo = 0;
    cur_action = 0;
    body_status = healthy;
    move_status = stay;
    next_x = pos_x;
    next_y = pos_y;
    hidden = false;
    beat_cnt = 0;
    jumping = false;
}
Monster::~Monster(){}
void Monster::draw(){

    // draw monster.
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    int sw = w / num_action; 
    int sh = h / 2;
    int offset_y = (jumping==true) ? JUMP_HIEIGHT: 0;
    offset_y += CHARACTER_OFFSET;
    int offset_x = (sw/2) - (GRID_SIZE/2);

    if (hidden == false){
        al_draw_scaled_bitmap(img, sw*cur_action, 0, sw, sh, pos_x-offset_x, pos_y-offset_y, sw, sh, 0);
    }else {
        al_draw_scaled_bitmap(img, sw*cur_action, sh, sw, sh, pos_x, pos_y-offset_y, sw, sh, 0);
    }
    // draw monster remaining lives.
    w = al_get_bitmap_width(heart_imgs["empty"]);
    h = al_get_bitmap_height(heart_imgs["empty"]);
    sw = w * 0.8; 
    sh = h * 0.8;
    if (remaining_lives != starting_lives){
        float remain = remaining_lives;

        for (int i=0; i<starting_lives; i++){
            if (remain <= 0){
                al_draw_scaled_bitmap(heart_imgs["empty"], 0 , 0, w, h, pos_x+i*sw, pos_y-sw, sw, sh, 0);
            }else if (remain < 1){
                al_draw_scaled_bitmap(heart_imgs["half"], 0 , 0, w, h, pos_x+i*sw, pos_y-sw, sw, sh, 0);
            }else {
                al_draw_scaled_bitmap(heart_imgs["full"], 0 , 0, w, h, pos_x+i*sw, pos_y-sw, sw, sh, 0);
            }
            remain --;
        }
    }


    jumping = false;
}
void Monster::change_action(){
    cur_action = cur_action + 1;
    if (cur_action == num_action) cur_action = 0;
}
bool Monster::is_dead(){
    return (remaining_lives <= 0);
}
void Monster::attack(){
    move_status = stay;
}
void Monster::be_attacked(float harm){
    remaining_lives = remaining_lives - harm;
    body_status = injured;
}
float Monster::get_power(){
    return power;
}
int Monster::get_next_x(){
    return next_x;
}
int Monster::get_next_y(){
    return next_y;
}
int Monster::get_drop_money(){
    return drop_money;
}
void Monster::pass_beat(){
    beat_cnt++;
    if (beat_cnt == beat_of_change){
        change_action();
        beat_cnt = 0;
    }
}
void Monster::move() {
    if (move_status == leave && body_status == healthy){
        //if (pos_x != next_x || pos_y != next_y){
            jumping = true;
        //}
        pos_x = next_x;
        pos_y = next_y;
        cur_dir = tmp_dir;
    }
    move_status = stay;
    body_status = healthy;
}



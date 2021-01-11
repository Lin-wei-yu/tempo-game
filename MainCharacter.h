#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED
#include <allegro5/allegro.h>
#include <vector>
#include <string>
#include <map>
#include "global.h"
#include "Object.h"
#include "Item.h"
#include "Block.h"
using namespace std;
class MainCharacter : public Object{
public:
    MainCharacter(ALLEGRO_BITMAP* img, vector<ALLEGRO_BITMAP*>& number_imgs, 
                map<string, ALLEGRO_BITMAP*>& heart_imgs, map<string, ALLEGRO_BITMAP*>& other_imgs);
    ~MainCharacter();
    void draw();
    void move();
    void early_move();
    bool is_dead();
    void attack();
    void be_attacked(float harm);
    void change_dir(DIR dir);
    float get_power();
    int get_next_x();
    int get_next_y();
    void find_money(int num);
    void draw_text(string str,int x, int y);
    void find_item(Item* item);
    bool shovable(Block block);
    void draw_items();
    void draw_life_and_coin();
    void change_action();
    void pass_beat();
    void stuck();
    ALLEGRO_BITMAP* get_shovel_img() { return item_list[ItemType::shovel][0]->get_img();};
    Item* get_bomb() { return item_list[ItemType::bomb][0]; };
protected:
    // define in subclass
    int num_action;
    float starting_lives;
    float remaining_lives;
    int tempo;
    int beat_of_change;

    // define in current class
    float power;
    int num_coin;
    int next_x;
    int next_y;
    int cur_tempo;
    int cur_action;
    int beat_cnt;
    bool jumping;
    DIR tmp_dir;
    MoveStatus move_status;
    BodyStatus body_status;
    map<ItemType, vector<Item*>> item_list;
    // imgs
    map<string, ALLEGRO_BITMAP*> heart_imgs;
    ALLEGRO_BITMAP* coin_img;
    vector<ALLEGRO_BITMAP*> number_imgs;
    ALLEGRO_BITMAP* alphabet_img;
};
#endif
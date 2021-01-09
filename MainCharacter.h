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
    MainCharacter(const char* path);
    ~MainCharacter();
    void draw();
    void move();
    void early_move();
    bool is_dead();
    // void attack(Monster* monster);
    void attack();
    void be_attacked(float power);
    void change_dir(DIR dir);
    int get_power();
    int get_next_x();
    int get_next_y();
    void find_money(int num);
    void draw_text(string str,int x, int y);
    void find_item(Item* item);
    bool shovable(Block block);
    void draw_items();
    void draw_life_and_coin();
private:
    DIR tmp_dir;
    float lives;
    MoveStatus move_status;
    BodyStatus body_status;
    int power;
    int tempo;
    int cur_tempo;
    vector<ALLEGRO_BITMAP*> heart_imgs;
    ALLEGRO_BITMAP* coin_img;
    ALLEGRO_BITMAP* text_img;
    int num_coin;
    int next_x;
    int next_y;
    map<ItemType, vector<Item*>> item_list;
};
#endif
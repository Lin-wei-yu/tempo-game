#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Object.h"
#include "global.h"
#include "Range.h"
#include <iostream>
#include <vector>
using namespace std;
typedef enum _ItemType{attack_tool, shovel, bomb, torch} ItemType;
class Item: public Object{
public:
    Item(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img);
    virtual void draw();
    void show(int x, int y, float enlarge_ratio);
    ItemType get_type();
    int get_level();
    virtual float get_power();
    virtual Range get_range();
    ALLEGRO_BITMAP* get_img(){ return img;};
    string get_command();
    
protected:
    // define in this class
    ALLEGRO_BITMAP* slot_img;
    string using_command;
    // define in sub-class
    ItemType item_type;
    int item_level;
    int num_animation;
    int value;
    vector<ALLEGRO_BITMAP*> number_imgs;
    float power;
    Range range;
    ALLEGRO_BITMAP* alphabet_img;
};
#endif
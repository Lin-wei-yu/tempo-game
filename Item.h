#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Object.h"
#include "global.h"
typedef enum _ItemType{attack_tool, shovel, bomb, torch} ItemType;
class Item: public Object{
public:
    Item(ALLEGRO_BITMAP* img, ALLEGRO_BITMAP* slot_img );
    virtual void draw();
    void show(int x, int y);
    ItemType get_type();
    int get_level();
    ALLEGRO_BITMAP* get_img() {return slot_img;};

protected:
    // define in this class
    ALLEGRO_BITMAP* slot_img;
    // define in sub-class
    ItemType item_type;
    int item_level;
    int num_animation;

};
#endif
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Object.h"
#include "global.h"
typedef enum _ItemType{attack, shovel, bomb, torch} ItemType;
class Item: public Object{
public:
    Item(ALLEGRO_BITMAP* img);
    virtual void attack(){};
    virtual void draw() = 0;
    virtual void show(int x, int y);
    ItemType get_type();
    
protected:
    ItemType item_type;
};
#endif
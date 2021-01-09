#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Object.h"
#include "global.h"
typedef enum _ItemFunc{attack, shovel, bomb, torch} ItemFunc;
class Item: public Object{
public:
    virtual void attack(){};
    virtual void draw() = 0;
    void show();
    
protected:
    ItemFunc item_func;
};

#endif
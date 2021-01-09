#ifndef DAGGER_H_INCLUDED
#define DAGGER_H_INCLUDED
#include "../Item.h"

class Dagger: public Item{
public:
    Dagger(ALLEGRO_BITMAP* img);
    ~Dagger(){};
protected:
    ItemFunc item_func;
    int power;
};

#endif
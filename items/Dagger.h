#ifndef DAGGER_H_INCLUDED
#define DAGGER_H_INCLUDED
#include "../Item.h"

class Dagger: public Object{
public:
    Dagger(){}
    ~Dagger(){}
protected:
    ItemFunc item_func;
};

#endif
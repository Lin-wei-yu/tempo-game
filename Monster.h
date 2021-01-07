#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include <allegro5/allegro.h>

#include "Object.h"
class Monster: public Object{
public:
    Monster(const char* path);
    ~Monster();
    void draw();
private:
    bool hidden;
};

#endif
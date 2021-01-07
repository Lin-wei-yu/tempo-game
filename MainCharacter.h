#ifndef MAINCHARACTER_H_INCLUDED
#define MAINCHARACTER_H_INCLUDED
#include <allegro5/allegro.h>
#include "global.h"
#include "Object.h"
class MainCharacter : public Object{
public:
    MainCharacter(const char* path);
    ~MainCharacter();
    void draw();
    void move(int dir);
private:
    
};
#endif
#ifndef Aria_H_INCLUDED
#define Aria_H_INCLUDED
#include "../MainCharacter.h"

class Aria:public MainCharacter{
public:
    Aria(ALLEGRO_BITMAP* img, vector<ALLEGRO_BITMAP*>& number_imgs
            ,map<string, ALLEGRO_BITMAP*>& heart_imgs, map<string, ALLEGRO_BITMAP*>& other_imgs);
    ~Aria();
private:
};
#endif
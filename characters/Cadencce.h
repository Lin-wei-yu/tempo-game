#ifndef Cadencce_H_INCLUDED
#define Cadencce_H_INCLUDED
#include "../MainCharacter.h"

class Cadencce:public MainCharacter{
public:
    Cadencce(ALLEGRO_BITMAP* img, vector<ALLEGRO_BITMAP*>& number_imgs
            ,map<string, ALLEGRO_BITMAP*>& heart_imgs, map<string, ALLEGRO_BITMAP*>& other_imgs);
    ~Cadencce();
private:
};
#endif
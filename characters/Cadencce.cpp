#include "Cadencce.h"


Cadencce::Cadencce(ALLEGRO_BITMAP* img, vector<ALLEGRO_BITMAP*>& number_imgs):MainCharacter(img, number_imgs){
    lives = 5;
    num_action = 4;
    tempo = 1;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
}
Cadencce::~Cadencce(){}
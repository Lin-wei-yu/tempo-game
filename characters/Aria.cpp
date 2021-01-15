#include "Aria.h"

Aria::Aria(ALLEGRO_BITMAP* img, vector<ALLEGRO_BITMAP*>& number_imgs
            ,map<string, ALLEGRO_BITMAP*>& heart_imgs, map<string, ALLEGRO_BITMAP*>& other_imgs):MainCharacter(img, number_imgs,heart_imgs,other_imgs){
    starting_lives = remaining_lives = 5;
    num_action = 4;
    beat_of_change = (BEAT_PER_TEMPO)/num_action;
}
Aria::~Aria(){}

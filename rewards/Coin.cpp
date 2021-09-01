#include "Coin.h"
// using namespace std;
Coin::Coin(int value, int x, int y, ALLEGRO_BITMAP* img):Reward(){
    pos_x = x;
    pos_y = y;
    this->value = value;
    this->img = img;
}
Coin::~Coin(){}

int Coin::get_value(){
    return value;
}
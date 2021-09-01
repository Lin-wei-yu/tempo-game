#ifndef COIN_H_INCLUDED
#define COIN_H_INCLUDED
#include "../Reward.h"
#include <utility>
using namespace std;

class Coin: public Reward{
public :
    Coin(int value, int x, int y, ALLEGRO_BITMAP* img); 
    ~Coin();
    int get_value();
private:
    int value;
};

#endif
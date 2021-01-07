#ifndef COIN_H_INCLUDED
#define COIN_H_INCLUDED
#include "../Reward.h"
#include <utility>
using namespace std;

class Coin: public Reward{
public :
    Coin(int dollar, int x, int y); 
    ~Coin();
private:
    int dollar;
};

#endif
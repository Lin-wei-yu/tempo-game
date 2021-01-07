#include "Coin.h"
// using namespace std;
Coin::Coin(int dollar, int x, int y){
    pos_x = x;
    pos_y = y;
    switch (dollar)
    {
    case 1:
        img = al_load_bitmap("assets/reward/resource_coin1.png");
        break;
    case 2:
        img = al_load_bitmap("assets/reward/resource_coin2.png");
        break;
    case 3:
        img = al_load_bitmap("assets/reward/resource_coin3.png");
        break;
    case 4:        
        img = al_load_bitmap("assets/reward/resource_coin4.png");
        break;
    case 5:
        img = al_load_bitmap("assets/reward/resource_coin5.png");
        break;
    default:
        break;
    }
}
Coin::~Coin(){}
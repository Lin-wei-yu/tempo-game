#ifndef REWARD_H_INCLUDED
#define REWARD_H_INCLUDED
#include "Object.h"
#include "global.h"
using namespace std;
class Reward: public Object{
public :
    // Reward(); 
    // ~Reward();
    void draw();
private:
    bool hidden;
};
#endif
#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <allegro5/allegro.h>
#include <vector>
#include "Object.h"

using namespace std;

class Map{
public:
    Map();
    ~Map();

    // void load_blocks();
    void draw();
private:
    ALLEGRO_BITMAP* basic;
    vector<pair<int,int>> blocks;
};


#endif
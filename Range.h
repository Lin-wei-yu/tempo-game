#ifndef RANGE_H_INCLUDED
#define RANGE_H_INCLUDED
#include "global.h"
class Range{
public:
    Range();
    Range(int up, int down, int left, int right);
    ~Range(){};
    void build_range(int up, int down, int left, int right);
    int get_up();
    int get_down();
    int get_left();
    int get_right();

private:
    int up; 
    int down; 
    int left; 
    int right;
};
#endif
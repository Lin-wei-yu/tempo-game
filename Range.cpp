#include "Range.h"
Range::Range(){
    this -> up = 0; 
    this -> down = 0; 
    this -> left = 0; 
    this -> right = 0;  
}
Range::Range(int up, int down, int left, int right){
    this -> up = up; 
    this -> down = down; 
    this -> left = left; 
    this -> right = right;
}
void Range::build_range(int up, int down, int left, int right){
    this -> up = up; 
    this -> down = down; 
    this -> left = left; 
    this -> right = right;    
}
int Range::get_up(){
    return up*GRID_SIZE;
}
int Range::get_down(){
    return down*GRID_SIZE;
}
int Range::get_left(){
    return left*GRID_SIZE;
}
int Range::get_right(){
    return right*GRID_SIZE;
}
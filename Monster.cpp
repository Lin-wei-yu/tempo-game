#include"Monster.h"
#include<string>
using namespace std;

Monster::Monster(const char* path){
    img = al_load_bitmap(path);
    pos_x = 100;
    pos_y = 100;
    hidden = false;
}
Monster::~Monster(){

}
void Monster::draw(){
    int w = al_get_bitmap_width(img);
    int h = al_get_bitmap_height(img);
    al_draw_scaled_bitmap(img, 0, 0, w/2, h/2, pos_x, pos_y, w/2, h/2, 0);
}
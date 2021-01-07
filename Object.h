#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <utility>
#include <allegro5/allegro5.h>
#include <string>
using namespace std;

typedef enum _BodyStatus{injured, healthy} BodyStatus;
typedef enum _MoveStatus {leave, stay} MoveStatus;

class Object {
public:
    Object() {
        img = NULL;
    }
    virtual ~Object() {
        delete img;
    }
    // pure function for drawing object
    virtual void draw() = 0;
    int get_x() {
        return pos_x;
    }
    int get_y() {
        return pos_y;
    }
protected:
    int pos_x;
    int pos_y;
    ALLEGRO_BITMAP* img;
};

#endif // OBJECT_H_INCLUDED
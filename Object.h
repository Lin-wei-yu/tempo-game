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
    Object() {}
    virtual ~Object() {}
    // pure function for drawing object
    virtual void draw() = 0;
    int get_x() {
        return pos_x;
    }
    int get_y() {
        return pos_y;
    }
protected:
    ALLEGRO_BITMAP* img;
    int pos_x;
    int pos_y;
};

#endif // OBJECT_H_INCLUDED
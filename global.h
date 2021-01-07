#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
=======
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define WINDOW_WIDTH 2000
#define WINDOW_HEIGHT 1500
#define FIELD_WIDTH 600
#define FIELD_HEIGHT 600

#define FONT_SIZE 12
#define GRID_WIDTH 40
#define GRID_HEIGHT 40
#include <map>
#include <string>

// define number of pictures for animation of the character 
// std::map <int, int> CHARACTER_DOC;
// CHARACTER_DOC[1] = 2;

// CHRACTER_DOC["assets/monster/slime_fire.png"] = 4;
// CHRACTER_DOC["assets/monster/slime_green.png"] = 4;
// CHRACTER_DOC["assets/monster/slime_ice.png"] = 4;
// CHRACTER_DOC["assets/monster/slime_orange.png"] = 4;
// CHRACTER_DOC["assets/main/TEMP_medic.png"] = 2;
// direction
enum DIR{UP, DOWN, LEFT, RIGHT};



#endif // GLOBAL_H_INCLUDED

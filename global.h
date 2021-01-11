#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define WINDOW_WIDTH 1440 // 24*60
#define WINDOW_HEIGHT 960 // 24*40

#define NUM_OF_WIDTH 60
#define NUM_OF_HEIGHT 40

#define FONT_SIZE 12
#define CHARACTER_OFFSET 12
#define JUMP_HIEIGHT 10
#define GRID_OFFSET 16
#define GRID_SIZE 24

#define TORCH_OFFSET 4
#define TORCH_SIZE 12
#define ENLARGE_PARAM 4
// direction
typedef enum _DIR {UP, DOWN, LEFT, RIGHT, NON} DIR;
#define DIR_KINDS 4
// for tempo
#define BEAT_PER_TEMPO 8

#endif // GLOBAL_H_INCLUDED

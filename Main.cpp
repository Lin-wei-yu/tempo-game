#include "GameWindow.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    GameWindow *TempoGame= new GameWindow();
    TempoGame->game_play();

    delete TempoGame;
    return 0;
}
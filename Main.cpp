#include "GameWindow.h"
#include <iostream>


int main(int argc, char *argv[])
{
    GameWindow *tempoGame= new GameWindow();
    tempoGame->game_play();

    delete tempoGame;
    return 0;
}
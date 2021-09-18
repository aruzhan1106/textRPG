#include "Game.h"

int main()
{
    Game game; //game initialized
    game.initGame();
    while (game.getPlaying()) { //while 'playing' is TRUE
        game.mainMenu();        //the game will be running
    }
    return 0;
}


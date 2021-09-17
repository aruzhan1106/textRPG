#include "Game.h"

int main()
{
    Game game; //game initialized
    game.initGame();
    /*inventory.addItem(Item());*/
    while (game.getPlaying()) {
        game.mainMenu();
    }
    return 0;
}


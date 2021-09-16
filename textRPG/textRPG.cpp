#include "Game.h"

int main()
{
    Game game; //game initialized
    game.initGame();

    Inventory inventory;
    /*inventory.addItem(Item());
    inventory.addItem(Item());
    inventory.addItem(Item());
    inventory.addItem(Item());
    inventory.addItem(Item());
    inventory.debugPrint(); */
    while (game.getPlaying()) {
        game.mainMenu();
    }
    return 0;
}


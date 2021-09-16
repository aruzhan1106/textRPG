#include "Game.h"

Game::Game() {
	choice = 0;
	playing = true;
};
Game::~Game() {};

void Game::initGame() {
	string name;
	cout << "MORTAL BLADE" << endl << endl;
	cout << "WELCOME, PLAYER" << endl << endl;
	cout << "Enter name for character:" << endl;
	getline(cin, name);
	character.initialize(name);
}

void Game::mainMenu() {
	cout << "MAIN MENU" << endl << endl;
	cout << "1: Explore" << endl;
	cout << "2: Rest" << endl;
	cout << "3: Show stats" << endl;
	cout << "0: Quit" << endl;
	cout << endl << "Choice: ";
	cin >> choice;
	switch (choice) {
	case 0: 
		playing = false;
		break;
	case 1: 
		character.explore();
		break;
	case 2:
		character.rest();
		break;
	case 3:
		character.printStats();
		break;
	default: break;
	}
}
bool Game::getPlaying() const {
	return this->playing;
}

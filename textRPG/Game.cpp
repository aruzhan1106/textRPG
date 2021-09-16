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
		explore();
		break;
	case 2:
		rest();
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

void Game::rest() {
	character.setHP(character.getMaxHP());
	cout << endl << endl << character.getName()<< " decides to lay down for a bit, and take a nap. " << endl;
	cout << character.getName() << "'s HP is fully restored" << endl << endl;
};
void Game::explore() {
	cout << endl << endl <<character.getName()<< " decides to look around" << endl;
	srand(time(NULL));
	int event = rand() % 2 + 0;
	if (event == 0) {
		find();
	}
	else if (1 <= event <= 2) {
		fight();
	}
};
void Game::find() {
	cout << character.getName()<< " finds a gold coin. +1 GOLD" << endl;
	cout << "+10 EXP" << endl << endl;
	character.setGold(character.getGold() + 1);
	character.setExp(character.getExp() + 10);
};
void Game::fight() {
	cout << character.getName()<< " encounters an enemy. It's a monster! Time to fight!" << endl;
	while (character.getHP() >= 1 && enemy.getEnemyHP() >= 1) {
		srand(time(NULL));
		int damagePoints = rand() % 10 + 5;
		enemy.setEnemyHP(enemy.getEnemyHP()-damagePoints);
		character.setHP(character.getHP()-damagePoints);
		cout << character.getName()<< " strikes the enemy dealing " << damagePoints << " damage. The monster now has " << enemy.getEnemyHP() << " HP." << endl;
		cout << "The monster takes a swing at " << character.getName() << " and deals " << damagePoints << " damage. " << character.getName() << " now has " << character.getHP()<< " HP." << endl << endl;
		if (enemy.getEnemyHP() < 1) {
			cout << "You win!" << endl;
			cout << "You gain +3 GOLD!" << endl;
			cout << "You gain +30 EXP!" << endl;
			character.setGold(character.getGold() + 3);
			character.setExp(character.getExp() + 30);
			enemy.setEnemyHP(20);
			break;
		}
		if (character.getHP() < 1) {
			enemy.setEnemyHP(20);
			cout << "You lose!" << endl;
			break;
		}
		cout << "What's "<< character.getName() << " going to do?"<<endl;
		cout << "1. Keep fighting" << endl;
		cout << "2. Run away" << endl << endl;
		int choiceFight;
		cout << "Choice: ";
		cin >> choiceFight;
		switch (choiceFight) {
		case 1: 
			continue;
		case 2:
			cout << "You flee" << endl;
			break;
		default: break;
		}
	}
}
#include "Game.h"

Game::Game() {
	choice = 0;
	playing = true;
};
Game::~Game() {};

void Game::initGame() {
	string name;
	cout << "MASS CALAMITY" << endl << endl;
	cout << "WELCOME, PLAYER" << endl << endl;
	cout << "Enter name for character:"<< endl;
	getline(cin, name);
	character.initialize(name);
}

void Game::mainMenu() {
	cout << endl<< "MAIN MENU" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Explore" << endl;
	cout << "2: Rest" << endl;
	cout << "3: Show Stats & Inventory" << endl;
	cout << endl << "Choice: ";
	cin >> choice;
	switch (choice) {
	case 0: 
		playing = false;
		break;
	case 1: 
		explore();
		character.levelUp();
		break;
	case 2:
		rest();
		break;
	case 3:
		character.printStats();
		inventory.debugPrint();
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
	srand((unsigned int)time(NULL));
	int event = rand() % 3;
	if (event == 0) {
		find();
	}
	else if (event>=1) {
		fight();
	}
};
void Game::find() {
	cout << character.getName()<< " finds a gold coin. +1 GOLD" << endl;
	cout << "+10 EXP" << endl << endl;
	cout << "You found an item: Rock" << endl;
	character.setGold(character.getGold() + 1);
	character.setExp(character.getExp() + 10);
	inventory.addItem(Item("Rock", "It's sharp, and cool to touch"));
};
void Game::fight() {
	cout << character.getName()<< " encounters an enemy. It's a monster! Time to fight!" << endl;
	while (character.getHP() >= 1 && enemy.getEnemyHP() >= 1) {
		srand((unsigned int)time(NULL));
		int damageToEnemy = rand() % 10 + 5;
		int damageToCharacter = rand() % 10 + 5;
		enemy.setEnemyHP(enemy.getEnemyHP()- damageToEnemy);
		character.setHP(character.getHP()- damageToCharacter);
		cout << character.getName()<< " strikes the enemy dealing " << damageToEnemy << " damage. The monster now has " << enemy.getEnemyHP() << " HP." << endl;
		if (enemy.getEnemyHP() < 1) {
			cout << "You win!" << endl;
			cout << "You gained +3 GOLD!" << endl;
			cout << "You gained +30 EXP!" << endl;
			cout << "You found an item: Rock" << endl;
			cout << "You found an item: Family Photograph" << endl;
			character.setGold(character.getGold() + 3);
			character.setExp(character.getExp() + 30);
			inventory.addItem(Item("Rock","It's sharp, and cool to touch"));
			inventory.addItem(Item("Family Photograph","It's a picture of your mom, dad, and brother. Everyone is smiling warmly."));
			enemy.setEnemyHP(20);
			break;
		}
		cout << "The monster takes a swing at " << character.getName() << " and deals " << damageToCharacter << " damage. " << character.getName() << " now has " << character.getHP() << " HP." << endl << endl;
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
			cout << "You run away from the enemy" << endl;
			break;
		default: break;
		}
	}
}
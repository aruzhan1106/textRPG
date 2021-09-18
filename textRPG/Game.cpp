#include "Game.h"

Game::Game() {
	choice = 0;
	playing = true;
};
Game::~Game() {};

void Game::initGame() {
	string name;
	cout << "ELYSIUM" << endl;
	cout << "\nWELCOME, PLAYER" << endl;
	cout << "\nEnter name for character:"<< endl;
	getline(cin, name);
	character.initialize(name);
	cout << "\n\nThere is a place called Elysium where the poisonous plant Belladonna grows." << endl;
	cout << name << " wakes up in one of the caves in this place." << endl;
	cout << "Due to the fact that the belladon plant grows very densely just next to this cave," << endl;
	cout << "the strong smell of the plant causes hallucinations. And now, in order to get out of " << endl;
	cout << "this cave, " << name << " will need to fight with hideous moth creatures." << endl;
}

void Game::mainMenu() {
	cout << endl<<"0: Quit" << endl;
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
	if (inventory.isInventoryFull() == false) {
		inventory.addItem(Item("Rock", 1, "It's sharp, and cool to the touch"));
	}
	else {
		cout << "Your inventory is full." << endl;
		cout << "The item was discarded." << endl;
	}
	updateStats();
};
void Game::fight() {
	cout << character.getName() << " encounters an enemy. It's a hideous mothlike creature! It's making a" << endl;
	cout<<"buzzing sound and slowly approaching you. Time to fight!" << endl;
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
			character.setGold(character.getGold() + 3);
			character.setExp(character.getExp() + 30);
			if (inventory.isInventoryFull() == false) {
				inventory.addItem(Item("Lead Pipe", 5, "Better weapon than a rock."));
			}
			else {
				cout << "Your inventory is full." << endl;
				cout << "The item was discarded." << endl;
			}
			updateStats();
			enemy.setEnemyHP(rand() % 20 + 10);
			break;
		}
		cout << "The monster takes a swing at " << character.getName() << " and deals " << damageToCharacter << " damage. " << character.getName() << " now has " << character.getHP() << " HP." << endl << endl;
		if (character.getHP() < 1) {
			enemy.setEnemyHP(rand() % 20 + 10);
			cout << "You lose!" << endl;
			break;
		}
		cout << "What's "<< character.getName() << " going to do?"<<endl;
		cout << "1. Keep fighting" << endl;
		cout << "2. Run away" << endl << endl;
		int choiceFight;
		cout << "Choice: ";
		cin >> choiceFight;
		if (choiceFight == 1) {
			continue;
		}
		else if (choiceFight == 2) {
			enemy.setEnemyHP(rand() % 20 + 10);
			cout << "You run away from the enemy" << endl;
			break;
		}
	}
}
void Game::updateStats() {
	character.setAttack(7+inventory.fetchItemAttack(inventory.bestAttackItem()));
}
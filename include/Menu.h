#include "DisplayObject.h"
#include <vector>
#include <string>
#include <GameController.h>
#include <Warrior.h>
#include <Board.h>
#pragma once

using std::vector;
using std::string;

class Menu {

public:

	Menu();
	void print(sf::RenderWindow& window);
	int checkMenuClick(sf::RenderWindow& window,const Board, string& objectName);
	string indexToString(const int index);

private:
//		array of all display objects of the menu
	//DisplayObject *m_buttons[11];
	GameController m_Objects;

//	const int options[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
};
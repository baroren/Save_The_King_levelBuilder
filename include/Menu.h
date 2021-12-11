#pragma once

#include "DisplayObject.h"
#include <vector>
#include <string>
#include <Warrior.h>
#include <Board.h>


using std::vector;
using std::string;

class Menu {

public:

	Menu();
	void print(sf::RenderWindow& window);
	int checkMenuClick(sf::RenderWindow& window,const Board);

	DisplayObject& indexToObject(const int index);

	void setObjects(const vector <DisplayObject*> objects);

private:
//		array of all display objects of the menu
	//DisplayObject *m_buttons[11];
//	GameController m_Objects;

	vector <DisplayObject*> m_objects;			//array of the objects

//	const int options[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
};
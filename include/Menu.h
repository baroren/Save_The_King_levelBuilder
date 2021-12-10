#include "DisplayObject.h"
#include <vector>
#include <string>
#include <GameController.h>
#include<Warrioir.h>
#pragma once

using std::vector;
using std::string;

class Menu {

public:

	Menu();
	void print(sf::RenderWindow& window);
	void check_if_clicked(sf::RenderWindow& window);

private:
//		array of all display objects of the menu
	//DisplayObject *m_buttons[11];
	GameController m_Objects;



	
};
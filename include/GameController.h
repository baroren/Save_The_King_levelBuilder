#pragma once

#include "Menu.h"
#include "DisplayObject.h"
#include <vector>
#include "string"
#include "King.h"
#include "Mage.h"
#include "Thief.h"
#include "Obstacle.h"
#include "Warrior.h"
#include "Board.h"
#include "DeleteButton.h"
#include "DeletePage.h"
#include "Save.h"


using std::vector;


class GameController
{
public:

//		num of rows, cols
	GameController(const int, const int,bool);
	DisplayObject*& getObject(const int index);
	void run();

private:
	vector <DisplayObject*> m_objects;
	Board m_board;
	Menu m_menu;

	//		paths to images
	const vector<string> m_imagesPath = { "king_image.png", "mage_image.png","warrior_image.png",
										"thief_image.png", "wall_image.png","gate_image.png",
										"fire_image.png", "ork_image.jpg", "key_image.png",
										"teleport_image.png", "throne_image.png","delete_butt.png","delete_page.png","save_page.png"};
};
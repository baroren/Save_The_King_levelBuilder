#include "DisplayObject.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Menu {

public:

	Menu();
	void print(sf::RenderWindow& window);


private:
//		array of all display objects of the menu
	DisplayObject m_buttons[11];

//		paths to images
	const vector<string> m_imagesPath = {"king_image.png", "mage_image.png","warrior_image.png",
										"thief_image.png", "wall_image.png","gate_image.png",
										"fire_image.png", "ork_image.jpg", "key_image.png",
										"teleport_image.png", "throne_image.png"};
};
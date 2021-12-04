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

//		paths to images, working only when full path entered, not sure why
	const vector<string> m_imagesPath = {"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/king_image.png", 
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/mage_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/warrior_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/thief_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/wall_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/gate_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/fire_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/ork_image1.jpg",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/key_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/teleport_image.png",
										"C:/מכללה/תכנות מונחה עצמים/תרגיל 4/ex04_oop/images/throne_image.png"};
};
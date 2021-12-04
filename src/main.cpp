

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Menu.h"

using std::vector;
using std::string;

int main()
{
	auto square = sf::RectangleShape(sf::Vector2f(50,50));
//		size of window, changes based on button size
	auto window = sf::RenderWindow (sf::VideoMode(980, 980), "Hello There");
	auto circle = sf::CircleShape(100);

	//square.setFillColor(sf::Color::Red);
	square.setFillColor(sf::Color(255, 0, 0, 90));
	circle.setFillColor(sf::Color(255, 0, 0, 90));


	//square.setOrigin(square.getSize());

	//square.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	Menu menu;

	while (window.isOpen())
	{
		window.clear();
		menu.print(window);
		window.display();
	}
}

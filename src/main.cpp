

#include <SFML/Graphics.hpp>


int main()
{
	auto square = sf::RectangleShape(sf::Vector2f(50,50));
	auto window = sf::RenderWindow (sf::VideoMode(500, 500), "Hello There");

	square.setFillColor(sf::Color::Red);

	//square.setOrigin(square.getSize());

	//square.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	while (window.isOpen())
	{
		window.clear();
		window.draw(square);
		window.display();
	}
}

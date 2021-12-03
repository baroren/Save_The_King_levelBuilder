

#include <SFML/Graphics.hpp>


int main()
{
	auto circle = sf::CircleShape (100);
	auto window = sf::RenderWindow (sf::VideoMode(500, 500), "Hello There");

	circle.setFillColor(sf::Color::Red);

	circle.setOrigin(circle.getRadius(), circle.getRadius());

	circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);

	while (window.isOpen())
	{
		window.clear();
		window.draw(circle);
		window.display();
	}
}



#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Menu.h"
#include <iostream>
#include "Board.h"
#pragma once
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	auto square = sf::RectangleShape(sf::Vector2f(50,50));
//		size of window, changes based on button size
	auto window = sf::RenderWindow (sf::VideoMode(980, 700), "Hello There");
	auto circle = sf::CircleShape(100);

	//square.setFillColor(sf::Color::Red);
	square.setFillColor(sf::Color(255, 0, 0, 90));
	circle.setFillColor(sf::Color(255, 0, 0, 90));


	//square.setOrigin(square.getSize());

	//square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	int rows_num, cols_num;

	cout << "how many rows?" << endl;
	cin >> rows_num;
	cout << "how many cols?" << endl;
	cin >> cols_num;
	sf::Vector2i position = sf::Mouse::getPosition();
	Menu menu;
	Board board(rows_num, cols_num);
	while (window.isOpen())
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);

		window.clear();
		menu.print(window);
		board.print(window);
		window.display();


		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (position.y < 70 && position.y>0)
				{
					menu.checkIfCliked(window, board);
				}
				cout << "clicked"<<position.y<<std::endl;
				break;
			
			}
		}
	}
}

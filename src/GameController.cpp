#include <SFML/Graphics.hpp>
#include "GameController.h"
#include <iostream>


using std::cout;
using std::endl;
using std::cin;

const int BUTTON_SIZE = 70;

GameController::GameController(const int rowNum, const int colNum)
	:m_objects(), m_board(rowNum, colNum, m_objects), m_menu()
{
	m_objects.push_back(new King(BUTTON_SIZE * 0, 0, m_imagesPath[0], 'K'));
	m_objects.push_back(new Mage(BUTTON_SIZE * 1, 0, m_imagesPath[1], 'M'));
	m_objects.push_back(new Warrior(BUTTON_SIZE * 2, 0, m_imagesPath[2], 'W'));
	m_objects.push_back(new Thief(BUTTON_SIZE * 3, 0, m_imagesPath[3], 'T'));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 4, 0, m_imagesPath[4], '='));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 5, 0, m_imagesPath[5], '#'));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 6, 0, m_imagesPath[6], '*'));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 7, 0, m_imagesPath[7], '!'));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 8, 0, m_imagesPath[8], 'F'));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 9, 0, m_imagesPath[9], 'T'));
	m_objects.push_back(new Obstacle(BUTTON_SIZE * 10, 0, m_imagesPath[10], '@'));

	m_board.setObjects(m_objects);
	m_menu.setObjects(m_objects);
}

void GameController::run()
{
	//		size of window, changes based on button size
	auto window = sf::RenderWindow(sf::VideoMode(980, 700), "Hello There");


	sf::Vector2i position = sf::Mouse::getPosition();
	//Board board(rows_num, cols_num);

	while (window.isOpen())
	{
		sf::Vector2i position = sf::Mouse::getPosition(window);

		window.clear();
		m_menu.print(window);
		m_board.print(window);
		window.display();

		int optionIndex = -1;

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

					optionIndex = m_menu.checkMenuClick(window, m_board,position);
				}

				 if (optionIndex != -1)
				{
					m_board.updateBoard(window, *m_objects[optionIndex], position, optionIndex);
					
				}

				cout << "optionIndex: " << optionIndex << endl;
				cout << "position.x: " << position.x << std::endl;
				cout << "position.y: " << position.y << std::endl;
				cout << '\n';
				break;

			}
		}
	}






}

DisplayObject*& GameController::getObject(const int index) {

	return m_objects[index];
}


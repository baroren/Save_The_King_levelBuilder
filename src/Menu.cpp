#include "Menu.h"
#include <iostream>

using std::cout;

//	if changed be sure to adjust the window size accordingly (window size = BUTTON_SIZE * 14)
const int BUTTON_SIZE = 70;


Menu::Menu()
	//m_buttons()
{
 
	
}

void Menu::setObjects(const vector <DisplayObject*> objects)
{
	m_objects = objects;
}

//	print all menu objects
void Menu::print(sf::RenderWindow& window)
{
//*auto button = sf::Texture();

	
	for (int i = 0;i <11;i++) 
	{
		

		//int imageSizeX = m_objects[i]->getTexture().getSize().x;			//width and height of image
		//int imageSizeY = m_objects[i]->getTexture().getSize().y;

		//auto buttonDisplay = sf::Sprite(m_objects[i]->getTexture());
		////			change size of sprite to BUTTON_SIZE
		//buttonDisplay.setScale(1.f / (imageSizeX / BUTTON_SIZE), 1.f / (imageSizeY / BUTTON_SIZE));

		//buttonDisplay.setPosition(sf::Vector2f(m_objects[i]->getLocation()));	//change position of sprite
		//window.draw(buttonDisplay);

		m_objects[i]->draw(window);
	}
}

int Menu::checkMenuClick(sf::RenderWindow& window, const Board board, sf::Vector2i& position)
{
	
	//sf::Vector2i position = sf::Mouse::getPosition(window);
	int optionIndex;

	for (optionIndex = 0; optionIndex < 11; optionIndex++)
	{
		if (position.x > BUTTON_SIZE * optionIndex && position.x < BUTTON_SIZE * (optionIndex + 1) )
		{
			int imageSizeX = m_objects[optionIndex]->getTexture().getSize().x;			//width and height of image
			int imageSizeY = m_objects[optionIndex]->getTexture().getSize().y;

			auto buttonDisplay = sf::Sprite(m_objects[optionIndex]->getTexture());
			buttonDisplay.setScale(1.f / (imageSizeX / BUTTON_SIZE), 1.f / (imageSizeY / BUTTON_SIZE));
			buttonDisplay.setColor(sf::Color(255, 255, 255, 128));
				
			while (true)
			{

				buttonDisplay.setPosition(sf::Mouse::getPosition(window).x-BUTTON_SIZE
					/2, sf::Mouse::getPosition(window).y-BUTTON_SIZE/2);
				//cout << "in check if Clicked " << i << std::endl;
				window.draw(buttonDisplay);
				this->print(window);
				board.print(window);
				window.display();
					
				window.clear();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//cout << "clicked yeh oh \n";
					//board.assignToBlock(window,m_Objects[i]);

					position = sf::Mouse::getPosition(window);

					if (position.y > BUTTON_SIZE)		//return option index if mouse clicked on board
					{
						return optionIndex;
					}

					return -1;
				}
			}
		}
	}

	cout << position.x;
}

//string Menu::indexToDisplayObject(const int index)
//{
//	switch (index)
//	{
//	case 0:
//		return "king";
//		break;
//	case 1:
//		return "mage";
//		break;
//	case 2:
//		return "warrior";
//		break;
//	case 3:
//		return "Thief";
//		break;
//	case 4:
//		return "";
//	}
//}

//DisplayObject& Menu::indexToObject(const int index)
//{
//	switch (index)
//	{
//	case 0:
//
//		return ;
//		break;
//	case 1:
//		return ;
//		break;
//	case 2:
//		return ;
//		break;
//	case 3:
//		return ;
//		break;
//	case 4:
//		return ;
//	}
//}
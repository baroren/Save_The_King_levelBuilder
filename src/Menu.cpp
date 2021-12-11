#include "Menu.h"
#include <iostream>

using std::cout;

//	if changed be sure to adjust the window size accordingly (window size = BUTTON_SIZE * 14)
const int BUTTON_SIZE = 70;


Menu::Menu()
	//m_buttons()
{

	
}

//	print all menu objects
void Menu::print(sf::RenderWindow& window)
{
//*auto button = sf::Texture();

	
	for (int i = 0;i <11;i++) 
	{
		

		int imageSizeX = m_Objects.getObject(i)->getTexture().getSize().x;			//width and height of image
		int imageSizeY = m_Objects.getObject(i)->getTexture().getSize().y;

		auto buttonDisplay = sf::Sprite(m_Objects.getObject(i)->getTexture());
		//			change size of sprite to BUTTON_SIZE
		buttonDisplay.setScale(1.f / (imageSizeX / BUTTON_SIZE), 1.f / (imageSizeY / BUTTON_SIZE));

		buttonDisplay.setPosition(sf::Vector2f(m_Objects.getObject(i)->getLocation()));	//change position of sprite
		window.draw(buttonDisplay);
	}
		

	
}

int Menu::checkMenuClick(sf::RenderWindow& window, const Board board, string& objectName)
{
	
	sf::Vector2i position = sf::Mouse::getPosition(window);
	int optionIndex;

	for (optionIndex = 0; optionIndex < 11; optionIndex++)
	{
		if (position.x > BUTTON_SIZE * optionIndex && position.x < BUTTON_SIZE * (optionIndex + 1) )
		{
			int imageSizeX = m_Objects.getObject(optionIndex)->getTexture().getSize().x;			//width and height of image
			int imageSizeY = m_Objects.getObject(optionIndex)->getTexture().getSize().y;

			auto buttonDisplay = sf::Sprite(m_Objects.getObject(optionIndex)->getTexture());
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

					position = sf::Mouse::getPosition();

					if (position.y > BUTTON_SIZE)		//return option index if mouse clicked on board
					{
						objectName = indexToString(optionIndex);
						return optionIndex;
					}
						
				}
			}
		}
	}

	//}
	cout << position.x;
}

string Menu::indexToString(const int index)
{
	switch (index)
	{
	case 0:
		return "king";
		break;
	case 1:
		return "mage";
		break;
	case 2:
		return "warrior";
		break;
	case 3:
		return "Thief";
		break;
	case 4:
		return "";
	}
}
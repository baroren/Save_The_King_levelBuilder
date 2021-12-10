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

void Menu::checkIfCliked(sf::RenderWindow& window, Board board)
{
	
	sf::Vector2i position = sf::Mouse::getPosition(window);
		for (int i = 0;i < 11;i++)
		{
			if (position.x > BUTTON_SIZE * i && position.x < BUTTON_SIZE * (i + 1) )
			{
				int imageSizeX = m_Objects.getObject(i)->getTexture().getSize().x;			//width and height of image
				int imageSizeY = m_Objects.getObject(i)->getTexture().getSize().y;

				auto buttonDisplay = sf::Sprite(m_Objects.getObject(i)->getTexture());
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
						board.assignToBlock(window,m_Objects[i]);
						return;
					}
					
				}
				
			}
		}

	//}
	cout << position.x;
}







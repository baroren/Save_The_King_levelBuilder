#include "Menu.h"
#include <iostream>

using std::cout;

//	if changed be sure to adjust the window size accordingly (window size = BUTTON_SIZE * 14)
const int BUTTON_SIZE = 70;

Menu::Menu()
	:m_buttons()
{
	for (int i = 0; i < 11; i++)
	{
		m_buttons[i].setCoord(BUTTON_SIZE * i, 0);	//set coordinates for all objects
		m_buttons[i].setImagePath(m_imagesPath[i]);	//set image paths for all objects
	}
}

//	print all menu objects
void Menu::print(sf::RenderWindow& window)
{
	auto button = sf::Texture();

	int imageSizeX, imageSizeY;
	for (int i = 0; i < 11; i++)
	{
		if (!button.loadFromFile(m_buttons[i].getImagePath()))	//load image
		{
			cout << "failed to load image\n";
			exit(EXIT_FAILURE);
		}

		imageSizeX = button.getSize().x;			//width and height of image
		imageSizeY = button.getSize().y;

		auto buttonDisplay = sf::Sprite(button);				
		
//			change size of sprite to BUTTON_SIZE
		buttonDisplay.setScale(1.f/(imageSizeX / BUTTON_SIZE), 1.f / (imageSizeY / BUTTON_SIZE));
		
		buttonDisplay.setPosition(sf::Vector2f(m_buttons[i].getLocation()));	//change position of sprite
		window.draw(buttonDisplay);
	}
}
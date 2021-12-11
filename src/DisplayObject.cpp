#include "DisplayObject.h"
#include "Board.h"

//	if changed be sure to adjust the window size accordingly (window size = BUTTON_SIZE * 14)
const int BUTTON_SIZE = 70;

DisplayObject::DisplayObject(const int x, const int y, const string imagePath, const int tag)
	:m_boardLocation(-1, -1)
{
	setCoord(x, y);
	setTextureAndPlayer(imagePath);
	m_tag = tag;
}


void DisplayObject::setCoord(const int x, const int y)
{
	m_location.x = x;
	m_location.y = y;
}

void DisplayObject::setBoardPos(const int x, const int y)
{
	m_boardLocation.x = x;
	m_boardLocation.y = y;
}

void DisplayObject::setTextureAndPlayer(const string imagePath)
{
	m_imagePath = imagePath;
	m_texture.loadFromFile(m_imagePath);
}

string DisplayObject::getImagePath() const
{
	return m_imagePath;
}
sf::Vector2i DisplayObject::getLocation() const
{
	return m_location;
}

sf::Vector2i DisplayObject::getBoardLocation() const
{
	return m_boardLocation;
}

sf::Texture& DisplayObject::getTexture()
{
	return m_texture;
}

int DisplayObject::getTag() const
{
	return m_tag;
}


void DisplayObject::draw(sf::RenderWindow& window)
{
	int imageSizeX = getTexture().getSize().x;			//width and height of image
	int imageSizeY = getTexture().getSize().y;

	auto buttonDisplay = sf::Sprite(getTexture());
	//			change size of sprite to BUTTON_SIZE
	buttonDisplay.setScale(1.f / (imageSizeX / BUTTON_SIZE), 1.f / (imageSizeY / BUTTON_SIZE));

	buttonDisplay.setPosition(sf::Vector2f(getLocation()));	//change position of sprite
	window.draw(buttonDisplay);
	//buttonDisplay.setPosition(140 + 70 * getBoardLocation().x, 140 + 70 * getBoardLocation().y);	//change position of sprite
	//window.draw(buttonDisplay);
}

void DisplayObject::isClicked()
{
	
}
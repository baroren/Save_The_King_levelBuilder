#include "DisplayObject.h"
#include "Board.h"

const int space = 70;

//	if changed be sure to adjust the window size accordingly (window size = BUTTON_SIZE * 14)
const int BUTTON_SIZE = 70;

DisplayObject::DisplayObject(const int x, const int y, const string imagePath, const char tag)
	:m_boardLocation(-1, -1)
{
	setCoord(x, y);
	setTextureAndPlayer(imagePath);
	m_tag = tag;
}


void DisplayObject::setCoord(const int x, const int y )
{
	m_location.x = x;
	m_location.y = y;
}

void DisplayObject::setBoardPos(const int x, const int y,int space)
{
	m_boardLocation.x = space+BUTTON_SIZE*(x+1);
	m_boardLocation.y = space+BUTTON_SIZE*(y+1);
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

char DisplayObject::getTag() const
{
	
	return m_tag;
}


void DisplayObject::draw(sf::RenderWindow& window, bool board,int x,int y,int space)
{
	int imageSizeX = getTexture().getSize().x;			//width and height of image
	int imageSizeY = getTexture().getSize().y;

	auto buttonDisplay = sf::Sprite(getTexture());
	//			change size of sprite to BUTTON_SIZE
	if (board)
	{
		buttonDisplay.setScale(1.f / (imageSizeX / space), 1.f / (imageSizeY / space));
		buttonDisplay.setPosition(space + BUTTON_SIZE * (x + 1)), space + BUTTON_SIZE * (y + 1));	//change position of sprite

	}
	else
	{
		buttonDisplay.setScale(1.f / (imageSizeX / BUTTON_SIZE), 1.f / (imageSizeY / BUTTON_SIZE));
		buttonDisplay.setPosition(sf::Vector2f(getLocation()));	//change position of sprite
	}
	window.draw(buttonDisplay);
	//buttonDisplay.setPosition(140 + 70 * getBoardLocation().x, 140 + 70 * getBoardLocation().y);	//change position of sprite
	//window.draw(buttonDisplay);
}

bool &DisplayObject::isClicked()
{
	return m_isOnBoard;
}
#include "DisplayObject.h"
#include "Board.h"


DisplayObject::DisplayObject(const int x, const int y, const string imagePath)
	 {
	this->setCoord(x, y);
	this->setTextureAndPlayer(imagePath);
}


void DisplayObject::setCoord(const int x, const int y)
{
	m_location.x = x;
	m_location.y = y;
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
sf::Texture& DisplayObject::getTexture()
{
	return m_texture;
}


void DisplayObject::draw() {}
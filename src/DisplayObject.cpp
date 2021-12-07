#include "DisplayObject.h"
#include "Board.h"


DisplayObject::DisplayObject(const int x, const int y, const string imagePath)
	:m_location(x, y), m_imagePath(imagePath) {}


void DisplayObject::setCoord(const int x, const int y)
{
	m_location.x = x;
	m_location.y = y;
}

void DisplayObject::setImagePath(const string imagePath)
{
	m_imagePath = imagePath;
}

string DisplayObject::getImagePath() const
{
	return m_imagePath;
}
sf::Vector2i DisplayObject::getLocation() const
{
	return m_location;
}

void DisplayObject::draw() {}
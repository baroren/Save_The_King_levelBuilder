#include <string>
#include <SFML/Graphics.hpp>
#include <DisplayObject.h>
#pragma once
using std::string;
//class DisplayObject;
class Obstacle : public DisplayObject
{
public:
	using DisplayObject::DisplayObject;
	bool  isClicked();//allways false
private:
	bool m_isOnBoard = false;
};
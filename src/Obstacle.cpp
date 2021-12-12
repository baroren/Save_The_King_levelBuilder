#include <Obstacle.h>

void Obstacle::setBoardCoord(const int x, const int y)
{
	//netanel here vector not working !!!!!
	
		m_boardLocation.x.push_back(x);
		m_boardLocation.y.push_back(y);
		m_onBoard = true;
}

bool Obstacle::isClicked()
{
	return false;
}
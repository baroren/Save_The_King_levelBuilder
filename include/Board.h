#include <SFML/Graphics.hpp>


class Board {
public:

//		c-tor based on window size (x width ,y height, menu size)
	Board(const int, const int);	

//		print base board (blank squares)
	void printBoard();		


private:
	sf::Vector2i m_location;		//	upper-left dot of board
	const int m_menuMargin = 25;

};
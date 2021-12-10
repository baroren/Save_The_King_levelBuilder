#include <SFML/Graphics.hpp>
#pragma once

class Board {
public:

//		c-tor based on window size (number of rows (height) ,number of cols (width))
	Board(const int, const int);	
	Board() = delete;

//		print base board (blank squares)
	void print(sf::RenderWindow& window) const;
	

private:
	sf::Vector2i m_location;		//	upper-left dot of board (is constant)
	int m_rowNum, m_colNum;			//	number of rows and cols

};
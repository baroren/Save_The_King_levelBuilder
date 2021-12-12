#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <DisplayObject.h>

using std::vector;

class Board {
public:

//		c-tor based on window size (number of rows (height) ,number of cols (width), reference to array of objects)
	Board(const int, const int, vector <DisplayObject*> m_objects,bool);

	void setObjects(const vector <DisplayObject*> m_objects);

//		print base board (blank squares)
	void print(sf::RenderWindow& window) const;
	
	void updateBoard(sf::RenderWindow& window, DisplayObject& object, const sf::Vector2i position,int);

	//char tagToChar(const int tag);

	void printObject(const int tag, sf::RenderWindow& window, const int row, const int col) const;

	void printByIndex(const int index, const int row, const int col) const;

	void deleteObjectFromBoard(sf::RenderWindow& window, DisplayObject& object, const sf::Vector2i position, int);
	int tagToInt(char);

	vector<string> getBtsBoard() const;

	void outputToFile() const;

private:
	sf::Vector2i m_location;			//	upper-left dot of board (is constant)
	int m_rowNum, m_colNum;				//	number of rows and cols

	vector<string> m_btsBoard;			//	representing the objects on board



	vector <DisplayObject*> m_objects;			//array of the objects
};
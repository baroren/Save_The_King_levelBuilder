#include "Board.h"

int space = 70;


Board::Board(const int row_num, const int col_num)
	:m_rowNum(row_num), m_colNum(col_num), m_location(140, 140) {}


//		print base board (blank squares)
void Board::print(sf::RenderWindow& window) const
{

//      needs to be fixed
    if (space * m_colNum >= window.getSize().x || space * m_rowNum >= window.getSize().y)
        space *= 0.75;

    for (int i = 0; i < m_rowNum + 1; i++)
    {
        sf::Vertex row[] =
        {
            sf::Vertex(sf::Vector2f(m_location.x, m_location.y + space * i)),
            sf::Vertex(sf::Vector2f(m_location.x + space * m_colNum, m_location.y + space * i))
        };

        window.draw(row, 2, sf::Lines);
    }

    for (int i = 0; i < m_colNum + 1; i++)
    {
        sf::Vertex col[] =
        {
            sf::Vertex(sf::Vector2f(m_location.x + space * i, m_location.y)),
            sf::Vertex(sf::Vector2f(m_location.x + space * i, m_location.y + space * m_rowNum))
        };

        window.draw(col, 2, sf::Lines);
    }

}
#include "Board.h"

int space = 70;
const int UPPER_LEFT_X = 140;
const int UPPER_LEFT_Y = 140;



Board::Board(const int row_num, const int col_num)
	:m_rowNum(row_num), m_colNum(col_num), m_location(140, 140) 
{

    vector <char> row;

    for (int i = 0; i < row_num; i++)
    {
        row.clear();

        for (int k = 0; k < col_num; k++)
            row.push_back(' ');

        m_btsBoard.push_back(row);
    }
}


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


void Board::printObject(sf::RenderWindow& window, const int optionIndex)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    int col_index = 0, row_index = 0;

//      find col and row of the mouse click, check the diff in the x, y of mouse click with cols of board
    while (mousePos.x - space > UPPER_LEFT_X + space * col_index)
        col_index++;

    while (mousePos.y - space > UPPER_LEFT_Y + space * row_index)
        row_index++;




}

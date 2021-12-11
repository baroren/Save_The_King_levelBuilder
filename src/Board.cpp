#include "Board.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

 int space = 70;
const int UPPER_LEFT_X = 140;
const int UPPER_LEFT_Y = 140;


Board::Board(const int row_num, const int col_num, vector <DisplayObject*> objects)
	:m_rowNum(row_num), m_colNum(col_num), m_location(140, 140), m_objects(objects)
{

    string row;

    for (int i = 0; i < row_num; i++)
    {
        row.clear();

        for (int k = 0; k < col_num; k++)
            row.push_back(-1);

        m_btsBoard.push_back(row);
    }
    
}

void Board::setObjects(const vector <DisplayObject*> objects)
{
    m_objects = objects;
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
  
    for (int i = 0; i < m_rowNum; i++)
    {
        for (int j = 0; j < m_colNum; j++)
        {
           std:: cout << m_btsBoard[i][j];
           if (m_btsBoard[i][j] == 'K')
               m_objects[0]->draw(window,true);
           if (m_btsBoard[i][j] == 'M')
               m_objects[1]->draw(window, true);
                    
        }
       // if (m_objects[i]->getBoardLocation().y > -1)
       //     m_objects[i]->draw(window);

    }
}

//void Board::printByIndex(const int index, const int row, const int col) const
//{
//    switch (index)
//    {
//    case 0:
//        return 'k';
//
//    default:
//        break;
//    }
//}


void Board::printObject(const int tag, sf::RenderWindow& window, const int row, const int col) const
{
    int imageSizeX = m_objects[tag]->getTexture().getSize().x;			//width and height of image
    int imageSizeY = m_objects[tag]->getTexture().getSize().y;

    auto buttonDisplay = sf::Sprite(m_objects[tag]->getTexture());
    //			change size of sprite to BUTTON_SIZE
    buttonDisplay.setScale(1.f / (imageSizeX / space), 1.f / (imageSizeY / space));

    buttonDisplay.setPosition(140 + 70 * col, 140 + 70 * row);

    window.draw(buttonDisplay);

    buttonDisplay.setPosition(m_objects[tag]->getLocation().x, m_objects[tag]->getLocation().y);

    window.draw(buttonDisplay);
}


void Board::updateBoard(sf::RenderWindow& window, DisplayObject& object, const sf::Vector2i position, int index)
{


    int col_index = 0, row_index = 0;

//      find col and row of the mouse click, check the diff in the x, y of mouse click with cols of board
    while (position.x - space > UPPER_LEFT_X + space * col_index)
        col_index++;
  

    while (position.y - space > UPPER_LEFT_Y + space * row_index)
        row_index++;

    cout << col_index << ' ' << row_index << endl;

    (*m_objects[index]).setBoardPos(col_index, row_index,space);

    m_btsBoard[row_index][col_index] = object.getTag();
    

}




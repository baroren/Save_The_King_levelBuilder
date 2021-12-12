#include "Board.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ios;

 int space = 70;
const int UPPER_LEFT_X = 140;
const int UPPER_LEFT_Y = 140;


Board::Board(const int row_num, const int col_num, vector <DisplayObject*> objects)
	:m_rowNum(0), m_colNum(0), m_location(140, 140), m_objects(objects)
{

    ifstream inputFile;

    inputFile.open("Board1.txt", ios::in);
    bool b = inputFile.is_open();

    string row;
    vector<string> temp;

    if (!inputFile.is_open())
    {
        cout << "how many rows?" << endl;
        cin >> m_rowNum;
        cout << "how many cols?" << endl;
        cin >> m_colNum;


        for (int i = 0; i < m_rowNum; i++)
        {
            row.clear();
            for (int k = 0; k < m_colNum; k++)
                row.push_back(' ');

            m_btsBoard.push_back(row);
        }
    }

    else
    {
        inputFile >> m_rowNum;      //input number of row and col
        inputFile >> m_colNum;
        inputFile.ignore();

//          save all relevant rows (without top bottom borders) to a temp array
        getline(inputFile, row);                
        for (int i = 0; i < m_rowNum; i++)
        {
            getline(inputFile, row);
            temp.push_back(row);
            row.clear();
        }

        int inputFileColIndex;

//          translate the temp array to the member array
        for (int currRow = 0; currRow < m_rowNum; currRow++)    
        {
            row.clear();

            for (int currCol = 0; currCol < m_colNum; currCol++)
            {
                inputFileColIndex = 1 + 2 * currCol;        //jumps in 2, starting from 1
                row.push_back(temp[currRow][inputFileColIndex]);
            }

            m_btsBoard.push_back(row);
        }
    }
}

void Board::outputToFile() const
{
    ofstream outputFile;
    string verticalBorder;

    for (int i = 0; i < 11; i++)        //top bottom border
        verticalBorder.push_back('-');

    outputFile.open("Board.txt");

    outputFile << verticalBorder << endl;

    for (int currRow = 0; currRow < m_rowNum; currRow++)
    {
        outputFile << '|';                                  //left border

        for (int currCol = 0; currCol < m_colNum; currCol++)
            outputFile << m_btsBoard[currRow][currCol] << ' ';  //print chars with one space between

        outputFile << '|' << endl;                          //right border
    }

    outputFile << verticalBorder << endl;
}

vector<string> Board::getBtsBoard() const
{
    return m_btsBoard;
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
           if (m_btsBoard[i][j] == 'K')
               m_objects[0]->draw(window,true,j,i,space);
           if (m_btsBoard[i][j] == 'M')
               m_objects[1]->draw(window, true,j,i, space);
           if (m_btsBoard[i][j] == 'W')
               m_objects[2]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == 'T')
               m_objects[3]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == '=')
               m_objects[4]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == '#')
               m_objects[5]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == '*')
               m_objects[6]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == '!')
               m_objects[7]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == 'F')
               m_objects[8]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == 'X')
               m_objects[9]->draw(window, true, j, i, space);
           if (m_btsBoard[i][j] == '@')
               m_objects[10]->draw(window, true, j, i,space);
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


    int col_index = -1, row_index = -1;

//      find col and row of the mouse click, check the diff in the x, y of mouse click with cols of board
    while (position.x - space > UPPER_LEFT_X + space * col_index)
        col_index++;
  

    while (position.y - space > UPPER_LEFT_Y + space * row_index)
        row_index++;

   // cout << col_index << ' ' << row_index << endl;

if(row_index<m_rowNum && col_index<m_colNum && row_index>=0 && col_index>=0)
    if (!m_objects[index]->isClicked())
    {
        
        if (m_btsBoard[row_index][col_index] == ' ')
        {
            m_btsBoard[row_index][col_index] = object.getTag();
            if (index < 4)
                m_objects[index]->isClicked() = true;
        }
    }
    

}

void Board::deleteObjectFromBoard(sf::RenderWindow& window, DisplayObject& object, const sf::Vector2i position, int index)
{
    int col_index = -1, row_index = -1;

    //      find col and row of the mouse click, check the diff in the x, y of mouse click with cols of board
    while (position.x - space > UPPER_LEFT_X + space * col_index)
        col_index++;


    while (position.y - space > UPPER_LEFT_Y + space * row_index)
        row_index++;

    if (row_index < m_rowNum && col_index < m_colNum && row_index >= 0 && col_index >= 0)
    { 
       
        if (m_btsBoard[row_index][col_index] != ' ')
        {
            int i = tagToInt(m_btsBoard[row_index][col_index]);
            m_btsBoard[row_index][col_index] = ' ';
            if (i < 4)
                m_objects[i]->isClicked() = false;
        }
    }
}

int Board:: tagToInt(char tag)
{
    switch (tag)
    {
    case 'K':
        return 0;
    case 'M':
        return 1;
    case 'W':
        return 2;
    case 'T':
        return 3;

    default:
        return 5;
        break;
    }
}

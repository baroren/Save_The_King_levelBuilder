
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "GameController.h"

#include <fstream>

using std::ofstream;

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{

	//ofstream outputFile;

	//outputFile.open("BoardNew");

	//outputFile << "hello darkness my old friend" << endl;




	bool newDraw = true;
	while (newDraw)
	{
		GameController gameController(0, 0);

		newDraw = gameController.run();
	}



}

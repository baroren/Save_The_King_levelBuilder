
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "GameController.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{

	int rows_num = 3, cols_num = 5;

	//cout << "how many rows?" << endl;
	//cin >> rows_num;
	//cout << "how many cols?" << endl;
	//cin >> cols_num;

	GameController gameController(rows_num, cols_num,false);
	gameController.run();


}

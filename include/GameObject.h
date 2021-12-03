#include <vector>
#include <SFML/Graphics.hpp>


using std::vector;

class GameObject {
protected:
	GameObject()

	void draw();

private:
	sf::Vector2f location;	//location of object
	vector<char> c;			//path to image
};
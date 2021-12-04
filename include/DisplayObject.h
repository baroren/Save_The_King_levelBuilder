#include <string>
#include <SFML/Graphics.hpp>

using std::string;

//	class for every intractable object on window
class DisplayObject {

public:

//		c-tor with x, y values and path to image
	DisplayObject(const int = 0, const int = 0, const string = "");

	void setCoord(const int, const int);
	void setImagePath(const string);

//		draws itself on window according to location
	void draw();

	string getImagePath() const;
	sf::Vector2i getLocation() const;

private:
	sf::Vector2i m_location;	//location of object
	string m_imagePath;			//path to image
};
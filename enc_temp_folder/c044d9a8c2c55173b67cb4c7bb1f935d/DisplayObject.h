#include <string>
#include <SFML/Graphics.hpp>
#pragma once

using std::string;

//	class for every intractable object on window
class DisplayObject {

public:

//		c-tor with x, y values and path to image
	DisplayObject(const int = 0, const int = 0, const string = "");
	void isClicked();
	void setCoord(const int, const int);
	void setTextureAndPlayer(const string);
	sf::Texture& getTexture();
//		draws itself on window according to location
	void draw();

	string getImagePath() const;
	sf::Vector2i getLocation() const;

private:
	sf::Vector2i m_location;	//location of object
	string m_imagePath;			//path to image
	sf::Texture m_texture;
};
#pragma once

#include <string>
#include <SFML/Graphics.hpp>

using std::string;

//	class for every intractable object on window
class DisplayObject {

public:

//		c-tor with x, y values, path to image and tag
	DisplayObject(const int = 0, const int = 0, const string = "King_image.png", const int = -1);
	void isClicked();
	void setCoord(const int, const int);
	void setTextureAndPlayer(const string);
	void setBoardPos(const int x, const int y);

	sf::Texture& getTexture();

//		draws itself on window according to location
	void draw(sf::RenderWindow& window);

	string getImagePath() const;
	sf::Vector2i getLocation() const;
	sf::Vector2i getBoardLocation() const;
	int getTag() const;

private:
	sf::Vector2i m_location;	//location of object
	sf::Vector2i m_boardLocation;
	string m_imagePath;			//path to image
	sf::Texture m_texture;

	int m_tag;			//name of object
};
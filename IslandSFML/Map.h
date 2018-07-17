#pragma once
#include <SFML/Graphics.hpp>

class Map {
public:
	Map();
	~Map();
	void renderMap(int _sizeX, int _sizeY);
	void mapDraw(sf::RenderWindow& _window);
private:

};


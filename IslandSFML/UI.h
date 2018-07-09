#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class UI {
private:
	sf::RenderWindow *window;
	std::vector<std::unique_ptr<sf::RectangleShape>> monitors;
	void createMonitor(int _posX, int _posY, int _sizeX, int _sizeY, sf::Color _fColor, sf::Color _oColor, int _thickness);
public:
	void drawUI();
	UI(sf::RenderWindow *window);
	~UI();
};


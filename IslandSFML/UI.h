#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class UI {
private:
	sf::RenderWindow *window;
	std::vector<std::unique_ptr<sf::RectangleShape>> monitors;
	void createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thickness);
public:
	void drawUI();
	UI(sf::RenderWindow *window);
	~UI();
};


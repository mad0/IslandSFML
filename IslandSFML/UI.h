#pragma once
#include <vector>
#include <SFML\Graphics.hpp>

class UI {
private:
	sf::RenderWindow *window;
	std::vector<std::unique_ptr<sf::RectangleShape>> monitors;
	sf::Font font;
	//std::vector<std::unique_ptr<sf::Text>> texts;
	std::map<int, std::unique_ptr<sf::Text>> texts;
	void createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thicknes, const std::string& _text);
public:
	void drawUI();
	sf::Vector2f getMonitorPosition(int _monitor);
	//Set Text
	void setText(int _monitor, const std::string& _text);
	//Add Text
	void addText(int _monitor, const std::string& _text);
	//Show Text
	void showText(int _monitor);
	UI(sf::RenderWindow *window);
	~UI();
};


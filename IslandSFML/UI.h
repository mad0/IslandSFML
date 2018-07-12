#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <memory>

class UI {
private:
	sf::RenderWindow *window;
	std::vector<std::shared_ptr<sf::RectangleShape>> monitors;
	sf::Font font;
	std::vector<std::pair<int, std::unique_ptr<sf::Text>>> texts;
	std::map<int, const std::string> feedbacks;
	void createMonitor(bool _enableText, float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thicknes);
public:
	enum Command {
		help = 0,
		move = 1,
		attack = 2
	};
	UI(sf::RenderWindow *window);
	~UI();
	void drawUI();
	sf::Vector2f getMonitorPosition(int _monitor);
	//Set Text
	void sendCommand(UI::Command _command);
	//Add Text
	void addText(int _monitor, const std::string& _text);
	//display text in specify monitor
	void displayText(int _monitor);
	
};


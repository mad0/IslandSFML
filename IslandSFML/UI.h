#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <memory>

class UI {
private:
	sf::RenderWindow *window;
	sf::Text textToConsole;
	std::vector<std::shared_ptr<sf::RectangleShape>> monitors;
	sf::Font font;
	std::vector<std::unique_ptr<sf::Text>> consoleOutput;
	std::map<std::string, std::string> feedbacks;
	void createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thicknes);
public:
	enum Monitors {
		Map,
		Stats,
		Loot,
		Monitor4,
		OutputText,
		Errors,
		Console,
		Skills,
	};
	UI(sf::RenderWindow *window);
	~UI();
	void drawUI();
	sf::Vector2f getMonitorPosition(UI::Monitors _monitor, float _nextLine);
	void sendCommand(std::string _command, UI::Monitors _monitor);
	void addText(UI::Monitors, const std::string& _text);
	void console(UI::Monitors, const std::string& _text);
};


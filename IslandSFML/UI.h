#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <memory>

class UI {
public:
	enum Monitors {
		Map,
		Stats,
		Loot,
		GameOutput,
		ConsoleOutput,
		Console,
		Skills,
	};
	enum Messages {
		OK,
		ERROR
	};
	UI();
	~UI();
	void drawUI(sf::RenderWindow &_window);
	sf::Vector2f getMonitorPosition(UI::Monitors _monitor, float _nextLine);
	void sendCommand(std::string _command);
	void writeToConsole(UI::Messages _messageStatus, const std::string& _text);
	void createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thicknes);
	void drawStars();
private:
	sf::Text textToConsole;
	sf::Font font;
	void createStars();
	std::vector<std::shared_ptr<sf::RectangleShape>> monitors;
	std::vector<std::unique_ptr<sf::Text>> consoleOutput;
	std::map<std::string, std::string> feedbacks;
	std::vector<std::unique_ptr<sf::CircleShape>> stars;
};


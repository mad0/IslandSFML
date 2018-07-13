#include "UI.h"
#include <iostream>


UI::UI(sf::RenderWindow *_window) : window(_window){
	font.loadFromFile("fonts/CGA.ttf");
	// 1:map:
	createMonitor(10, 10, 500, 480, sf::Color::Black, sf::Color::Green, 1);
	// 2:stats
	createMonitor(520, 10, 375, 480, sf::Color::Black, sf::Color::Green, 1);
	// 3:loot
	createMonitor(905, 10, 365, 480, sf::Color::Black, sf::Color::Green, 1);
	// 4:output messages
	createMonitor(10, 500, 780, 160, sf::Color::Black, sf::Color::Green, 1);
	// 5:output messages
	createMonitor(800, 500, 470, 120, sf::Color::Black, sf::Color::Green, 1);
	// 6:errors
	createMonitor(800, 630, 470, 30, sf::Color::Black, sf::Color::Green, 1);
	// 7:chat
	createMonitor(10, 670, 300, 40, sf::Color::Black, sf::Color::Green, 1);
	// 8:skills
	createMonitor(320, 670, 950, 40, sf::Color::Black, sf::Color::Green, 1);
	// console settings
	textToConsole.setCharacterSize(16);
	textToConsole.setFont(font);
	feedbacks = {
		{ "help", "Avaliable commands: help, attack, move." },
		{ "move", "Move to specify coordinates." },
		{ "attack",  "Attack enemy!" },
	};
	std::cout << "ODPALAM UI...\n";
}

UI::~UI() {
	std::cout << "NISZCZE UI...\n";
}

void UI::createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thickness) {
	int mIndex = monitors.size();
	monitors.emplace_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(_sizeX, _sizeY)));
	monitors[mIndex]->setPosition(_posX, _posY);
	monitors[mIndex]->setFillColor(_fColor);
	monitors[mIndex]->setOutlineColor(_oColor);
	monitors[mIndex]->setOutlineThickness(_thickness);
}
 
void UI::drawUI() {
	for (auto& m : monitors)
		window->draw(*m);
	window->draw(textToConsole);
	for (auto& t : consoleOutput) {
			window->draw(*t);
	}
}

sf::Vector2f UI::getMonitorPosition(UI::Monitors _monitor, float _nextLine) {
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 6.5 + _nextLine*22);
}

void UI::sendCommand(std::string _command, UI::Monitors _monitor) {
 	//for (auto& f : feedbacks) {
	//	if (f.first == _command) {
	//		
	//	}
	//}
	std::map<std::string, std::string>::iterator it = feedbacks.find(_command);
	if (it == feedbacks.end())
		console(Monitors::Errors, "Command not found.");
	else 
		addText(_monitor, it->second);
}

void UI::addText(UI::Monitors _monitor, const std::string & _text) {
	// make text -> texts vector
	std::unique_ptr<sf::Text> tempText = std::make_unique<sf::Text>(_text, font, 17);
	int textSize = consoleOutput.size();
	// set text properties to specify monitor
	tempText->setPosition(getMonitorPosition(_monitor, textSize));
	//texts[tIndex]->setFillColor(sf::Color::Yellow);
	consoleOutput.emplace_back(std::move(tempText));
}

void UI::console(UI::Monitors _monitor, const std::string & _text) {
	if (_monitor == UI::Monitors::Errors) {
		textToConsole.setString(_text);
		textToConsole.setPosition(getMonitorPosition(_monitor, -.1));
		textToConsole.setCharacterSize(16);
		textToConsole.setFillColor(sf::Color::Red);
		monitors[5]->setOutlineColor(sf::Color::Red);
	}
	else {
		textToConsole.setString(_text);
		textToConsole.setFillColor(sf::Color::Green);
		textToConsole.setPosition(getMonitorPosition(_monitor, 0));
		monitors[5]->setOutlineColor(sf::Color::Green);
	}
	
}

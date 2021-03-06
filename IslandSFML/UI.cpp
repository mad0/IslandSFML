#include "UI.h"
#include <iostream>
#include <random>

static std::random_device randDevice;
static std::mt19937 mt(randDevice());

UI::UI() {

	font.loadFromFile("fonts/CGA.ttf");
	// 1:map:
	createMonitor(10, 10, 885, 480, sf::Color::Black, sf::Color(229, 229, 229, 255), 1);
	// 3:loot
	createMonitor(905, 10, 365, 480, sf::Color(229, 229, 229, 255), sf::Color(51, 51, 0, 255), 1);
	// 4:game messages
	createMonitor(10, 500, 780, 160, sf::Color(229, 229, 229, 255), sf::Color(51, 51, 0, 255), 1);
	// 5:console output
	createMonitor(800, 500, 470, 160, sf::Color(229, 229, 229, 255), sf::Color(51, 51, 0, 255), 1);
	// 6:chat
	createMonitor(10, 670, 300, 40, sf::Color(229, 229, 229, 255), sf::Color(51, 51, 0, 255), 1);
	// 7:skills
	createMonitor(320, 670, 950, 40, sf::Color(229, 229, 229, 255), sf::Color(51, 51, 0, 255), 1);
	// 8: map borders 1
	//createMonitor(30, 30, 480, 460, sf::Color::Black, sf::Color::Green, 1);
	// console settings
	textToConsole.setCharacterSize(16);
	textToConsole.setFont(font);
	feedbacks = {
		{ "help", "Avaliable commands: help, attack, move." },
		{ "move", "Move to specify coordinates." },
		{ "attack",  "Attack enemy!" },
		{ "loot",  "Loot body" }
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


float UI::calculateStars(int _starNumber, int _starsNumber) {
	if (_starNumber <= _starsNumber) {
		static std::uniform_real_distribution<float> dist(0.5, 1.5);
		std::cout << 1 << "\n";
		return dist(mt);
	}
	else {
		static std::uniform_real_distribution<float> dist(1.8, 2.0);
		std::cout << 2 << "\n";
		return dist(mt);
	}	
}
 
void UI::drawUI(sf::RenderWindow &_window) {
	for (auto& m : monitors)
		_window.draw(*m);
	_window.draw(textToConsole);
	for (auto& t : consoleOutput)
			_window.draw(*t);
}

sf::Vector2f UI::getMonitorPosition(UI::Monitors _monitor, float _nextLine) {
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 6.5 + _nextLine*22);
}

void UI::sendCommand(std::string _command) {
	auto it = feedbacks.find(_command);
	if (it == feedbacks.end())
		writeToConsole(UI::Messages::ERROR, "Command not found.");
	else {
		writeToConsole(UI::Messages::OK, it->first);
		std::unique_ptr<sf::Text> tempText = std::make_unique<sf::Text>(it->second, font, 17);
		int textSize = consoleOutput.size();
		tempText->setPosition(getMonitorPosition(UI::Monitors::ConsoleOutput, textSize));
		tempText->setFillColor(sf::Color::Blue);
		consoleOutput.emplace_back(std::move(tempText));
	}
}

void UI::writeToConsole(UI::Messages _messageStatus, const std::string & _text) {
	if (_messageStatus == UI::Messages::ERROR) {
		textToConsole.setString(_text);
		textToConsole.setPosition(getMonitorPosition(UI::Monitors::Console, 0.1));
		textToConsole.setCharacterSize(16);
		textToConsole.setFillColor(sf::Color::Red);
		monitors[UI::Monitors::Console]->setOutlineColor(sf::Color::Red);
	}
	else {
		textToConsole.setString(_text);
		textToConsole.setFillColor(sf::Color::Black);
		textToConsole.setPosition(getMonitorPosition(UI::Monitors::Console, 0.1));
		monitors[UI::Monitors::Console]->setOutlineColor(sf::Color(138, 127, 141,255));
	}
}

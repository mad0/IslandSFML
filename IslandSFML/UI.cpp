#include "UI.h"
#include <iostream>




UI::UI(sf::RenderWindow *_window) : window(_window){
	font.loadFromFile("fonts/CGA.ttf");
	feedbacks = {
		{ 0, "Avaliable commands: help, attack, move." },
		{ 1, "Move to specify coordinates." },
		{ 2,  "Attack enemy!" },
	};

	// map
	createMonitor(false, 10, 10, 500, 500, sf::Color::Black, sf::Color::Green, 1);
	// stats window
	createMonitor(false, 520, 10, 375, 500, sf::Color::Black, sf::Color::Green, 1);
	// stats loot
	createMonitor(false, 905, 10, 365, 500, sf::Color::Black, sf::Color::Green, 1);
	//monitor 0 - chat
	createMonitor(true, 10, 670, 300, 40, sf::Color::Black, sf::Color::Green, 1);
	//monitor 1 - skills
	createMonitor(false, 320, 670, 950, 40, sf::Color::Black, sf::Color::Green, 1);
	//monitor 1 output messages
	createMonitor(true, 10, 520, 780, 140, sf::Color::Black, sf::Color::Green, 1);
	//monitor 2 - output messages
	createMonitor(true, 800, 520, 470, 140, sf::Color::Black, sf::Color::Green, 1);
	std::cout << "ODPALAM UI...\n";
}

UI::~UI() {
	std::cout << "NISZCZE UI...\n";
}


void UI::createMonitor(bool _enableText, float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thickness) {
	int mIndex = monitors.size();
	monitors.emplace_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(_sizeX, _sizeY)));
	monitors[mIndex]->setPosition(_posX, _posY);
	monitors[mIndex]->setFillColor(_fColor);
	monitors[mIndex]->setOutlineColor(_oColor);
	monitors[mIndex]->setOutlineThickness(_thickness);
	if (_enableText) {
		int tIndex = texts.size();
		addText(tIndex, "line1");
		addText(tIndex, "line1");
		addText(tIndex, "line1");
		//texts[tIndex]->setPosition(getMonitorPosition(mIndex));
		//texts[tIndex]->setFillColor(sf::Color::Yellow);
	}
	
}
 
void UI::displayText(int _monitor) {
	sf::Text text;
	text.setFont(font);
	text.setPosition(getMonitorPosition(_monitor));
	text.setString("1");
}
void UI::drawUI() {
	for (auto& m : monitors)
		window->draw(*m);
	//for (auto &t : texts)
	//	window->draw(t.second);
	
}

sf::Vector2f UI::getMonitorPosition(int _monitor) {
	if (_monitor == 0)
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 8);
	if (_monitor == 1)
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 8);
	if (_monitor == 2)
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 8);
}

void UI::sendCommand(UI::Command _command) {
	//std::cout << _command;
 	for (auto& f : feedbacks) {
		if (f.first == _command) {
		std::cout << f.second;
		}
	}
}

void UI::addText(int _monitor, const std::string & _text) {
	texts.emplace_back(std::make_pair(_monitor, std::make_unique<sf::Text>(_text, font, 16)));
	//std::cout << texts.size()<<"\n";
}

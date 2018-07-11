#include "UI.h"
#include <iostream>


void UI::showText(int _monitor) {
	//while (texts[_monitor] == _monitor)
}

UI::UI(sf::RenderWindow *_window) : window(_window){
	font.loadFromFile("fonts/CGA.ttf");
	//monitor 0 - chat
	createMonitor(10, 670, 300, 40, sf::Color::Black, sf::Color::Green, 1, "_");
	//monitor 1 - skills
	createMonitor(320, 670, 950, 40, sf::Color::Black, sf::Color::Green, 1, "");
	//monitor 2 - output messages
	createMonitor(800, 520, 470, 140, sf::Color::Black, sf::Color::Green, 1, "");
	
	std::cout << "ODPALAM UI...\n";
}

UI::~UI() {
	std::cout << "NISZCZE UI...\n";
}


void UI::createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thickness, const std::string& _text) {
	monitors.emplace_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(_sizeX, _sizeY)));
	int index = monitors.size();
	monitors[index - 1]->setPosition(_posX, _posY);
	monitors[index - 1]->setFillColor(_fColor);
	monitors[index - 1]->setOutlineColor(_oColor);
	monitors[index - 1]->setOutlineThickness(_thickness);
	texts.insert(std::make_pair(index-1, std::make_unique<sf::Text>(_text, font, 17)));
	texts[index - 1]->setPosition(getMonitorPosition(index - 1));
	texts[index - 1]->setFillColor(sf::Color::Yellow);
}

void UI::drawUI() {
	for (auto& m : monitors)
		window->draw(*m);
	/for (auto &t : texts)
	//	window->draw(*t.second);
	
}

sf::Vector2f UI::getMonitorPosition(int _monitor) {
	if (_monitor == 0)
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 8);
	if (_monitor == 1)
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 8);
	if (_monitor == 2)
		return sf::Vector2f(monitors[_monitor]->getPosition().x + 10, monitors[_monitor]->getPosition().y + 8);
}

void UI::setText(int _monitor, const std::string& _text) {
	texts[_monitor]->setString(_text);
}

void UI::addText(int _monitor, const std::string & _text) {
	texts.insert(std::make_pair(_monitor, std::make_unique<sf::Text>(_text, font, 16)));
	std::cout << +texts.size()<<"\n";
}

#include "UI.h"
#include <iostream>


UI::UI(sf::RenderWindow *_window) : window(_window){
	createMonitor(5, 5, 200, 200, sf::Color::Black, sf::Color::Red, 2);
	createMonitor(5, 210, 400, 200, sf::Color::Yellow, sf::Color::Red, 2);
	std::cout << "ODPALAM UI...\n";
}

UI::~UI() {
	std::cout << "NISZCZE UI...\n";
}


void UI::createMonitor(float _posX, float _posY, float _sizeX, float _sizeY, sf::Color _fColor, sf::Color _oColor, float _thickness) {
	monitors.emplace_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(_sizeX, _sizeY)));
	int index = monitors.size();
	monitors[index - 1]->setPosition(_posX, _posY);
	monitors[index - 1]->setFillColor(_fColor);
	monitors[index - 1]->setOutlineColor(_oColor);
	monitors[index - 1]->setOutlineThickness(_thickness);
}

void UI::drawUI() {
	for (auto& m : monitors)
		window->draw(*m);
}

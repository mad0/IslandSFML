#include "uiText.h"


uiText::uiText(const std::string& _text, sf::Vector2f _pos) {
	font.loadFromFile("fonts/CGA.ttf");
}

uiText::~uiText() {
}

void uiText::createText() {

	text.setFont(fonty);
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(15);
	text.setPosition(10, 10);
}
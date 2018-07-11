#pragma once
#include <string>
#include <SFML\Graphics.hpp>

class uiText {
private:
	sf::Font font;
	std::vector<sf::Text> texts;
	void createText();
public:
	uiText(const std::string& _text, sf::Vector2f _pos);
	~uiText();
};


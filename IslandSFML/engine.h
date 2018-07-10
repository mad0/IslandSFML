#pragma once
#include <SFML\Graphics.hpp>
#include "UI.h"
#include <memory>

class Engine {
private:
	sf::RenderWindow window;
	std::unique_ptr<UI> ui;
	sf::String inputText;
	sf::String dupa;
	sf::Font fonty;
	sf::Text text;
public:
	Engine();
	~Engine();
	void mainLoop();
	void input();
	void update();
	void draw();
};

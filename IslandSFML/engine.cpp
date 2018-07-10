#include "engine.h"
#include <iostream>

Engine::Engine() : ui(new UI(&window)){
	window.create(sf::VideoMode(1280, 720), "Island");
	fonty.loadFromFile("fonts/CGA.ttf");
	text.setFont(fonty);
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(15);
	text.setPosition(10, 10);

}

Engine::~Engine() {
}

void Engine::mainLoop() {
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode == 13) {
					std::cout << static_cast<char>(event.text.unicode) << "\n";
					//inputText.erase(inputText.getSize() - 1, 1);
					inputText += ".\n\n";
					text.setString(inputText);
				}
				else {
					inputText += static_cast<char>(event.text.unicode);
					std::cout << static_cast<char>(event.text.unicode) << "\n";
					text.setString(inputText+"_");
				}
				
			}
		}
		update();
		draw();
		
	}
}

void Engine::input() {

}

void Engine::update() {
}

void Engine::draw() {
	window.clear(sf::Color::Black);
	ui->drawUI();
	window.draw(text);
	window.display();
}

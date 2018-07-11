#include "engine.h"
#include <iostream>

Engine::Engine() : ui(new UI(&window)){
	window.create(sf::VideoMode(1280, 720), "Island");
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
					ui->addText(2, inputText);
					inputText = "";
					ui->setText(0, inputText);
				}
				else {
					inputText += static_cast<char>(event.text.unicode);
					//std::cout << static_cast<char>(event.text.unicode) << "\n";
					ui->setText(0, inputText+"_");
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
	//std::string w = inputText;
	//std::cout << w + "\n";
}

void Engine::draw() {
	window.clear(sf::Color::Black);
	ui->drawUI();
	window.display();
}

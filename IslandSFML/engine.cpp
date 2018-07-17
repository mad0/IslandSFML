#include "engine.h"
#include <iostream>

Engine::Engine() : ui(new UI){
	window.create(sf::VideoMode(1280, 720), "Island", sf::Style::Default);
	//window.create(sf::VideoMode(1920, 1080), "Island", sf::Style::Fullscreen);
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
					ui->sendCommand(inputText);
					inputText.clear();
				}
				else if (inputText.getSize()!=0 && event.text.unicode == 8) {
					inputText.erase(inputText.getSize() - 1, 1);
					std::cout << inputText.getSize() << "\n";
					ui->writeToConsole(UI::Messages::OK, inputText);
				}
				else {
					if (event.text.unicode != 8) {
						inputText += static_cast<char>(event.text.unicode);
						//std::cout << static_cast<char>(event.text.unicode) << "\n";
						ui->writeToConsole(UI::Messages::OK, inputText);
						}	
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
	//window.clear(sf::Color(138, 127, 141, 240));
	//window.clear(sf::Color(145, 163, 176, 255));
	window.clear(sf::Color(138, 127, 141, 255));
	ui->drawUI(window);
	window.display();
}

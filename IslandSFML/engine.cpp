#include "engine.h"

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
		}
		draw();
	}
}

void Engine::input() {
}

void Engine::update() {
}

void Engine::draw() {
	window.clear(sf::Color::Cyan);
	ui->drawUI();
	window.display();
}

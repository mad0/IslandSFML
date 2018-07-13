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
				//switch (event.text.unicode) {
				//	case 'move': {
				//		std::cout << "ENTER";
				//		ui->sendCommand(UI::Command::attack);
				//		break; }
				//	case 8: {
				//		std::cout << "BACKSPACE";
				//		break; }
				//	default:
				//		std::cout << static_cast<char>(event.text.unicode);
				///	break;
				//}
				if (event.text.unicode == 13) {
					//inputText.erase(inputText.getSize() - 1, 1);
					ui->sendCommand(inputText, UI::Monitors::OutputText);
					inputText.clear();
					//ui->console(UI::Monitors::Console, inputText);
				}
				else {
					inputText += static_cast<char>(event.text.unicode);
					//std::cout << static_cast<char>(event.text.unicode) << "\n";
					ui->console(UI::Monitors::Console, inputText);
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

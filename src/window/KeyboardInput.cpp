#include <window/KeyboardInput.h>

#include <SFML/Window.hpp>

namespace window {

KeyboardInput::KeyboardInput() {}

std::vector<PressedKey> KeyboardInput::getInput() {
	std::vector<PressedKey> input;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)) {
		input.push_back(PressedKey::arrowLeft);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)) {
		input.push_back(PressedKey::arrowRight);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)) {
		input.push_back(PressedKey::arrowUp);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)) {
		input.push_back(PressedKey::arrowDown);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space)) {
		input.push_back(PressedKey::space);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::LControl)) {
		input.push_back(PressedKey::leftControl);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::RControl)) {
		input.push_back(PressedKey::rightControl);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::LShift)) {
		input.push_back(PressedKey::leftShift);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
		input.push_back(PressedKey::A);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
		input.push_back(PressedKey::D);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
		input.push_back(PressedKey::S);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
		input.push_back(PressedKey::W);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num0)) {
		input.push_back(PressedKey::Num0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num1)) {
		input.push_back(PressedKey::Num1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num2)) {
		input.push_back(PressedKey::Num2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num3)) {
		input.push_back(PressedKey::Num3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num4)) {
		input.push_back(PressedKey::Num4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num6)) {
		input.push_back(PressedKey::Num6);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Num8)) {
		input.push_back(PressedKey::Num8);
	}

	input.push_back(PressedKey::any);

	return input;
}



}
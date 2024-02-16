#include <window/JoystickInput.h>

#include <SFML/Window.hpp>

namespace window {

JoystickInput::JoystickInput() {}

std::vector<PressedButton> JoystickInput::getInput() {
	if (!sf::Joystick::isConnected(0)) {
		return {};
	}

	sf::Joystick::update();
	std::vector<PressedButton> input;

	if (sf::Joystick::hasAxis(0, sf::Joystick::X)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -0.1) {
			input.push_back(PressedButton::leftX);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 0.1) {
			input.push_back(PressedButton::rightX);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::Y)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -0.1) {
			input.push_back(PressedButton::upY);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 0.1) {
			input.push_back(PressedButton::downY);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::Z)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -0.1) {
			input.push_back(PressedButton::leftX);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > 0.1) {
			input.push_back(PressedButton::rightX);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::R)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::R) < -0.1) {
			input.push_back(PressedButton::upY);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::R) > 0.1) {
			input.push_back(PressedButton::downY);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::U)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::U) < -0.1) {
			input.push_back(PressedButton::leftU);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::U) > 0.1) {
			input.push_back(PressedButton::rightU);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::V)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::V) < -0.1) {
			input.push_back(PressedButton::upV);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::V) > 0.1) {
			input.push_back(PressedButton::downV);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::PovX)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -0.1) {
			input.push_back(PressedButton::hatLeftX);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > 0.1) {
			input.push_back(PressedButton::hatRightX);
		}
	}
	if (sf::Joystick::hasAxis(0, sf::Joystick::PovY)) {
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -0.1) {
			input.push_back(PressedButton::hatUpY);
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 0.1) {
			input.push_back(PressedButton::hatDownY);
		}
	}

	if (sf::Joystick::isButtonPressed(0, 0)) {
		input.push_back(PressedButton::A);
	}
	if (sf::Joystick::isButtonPressed(0, 1)) {
		input.push_back(PressedButton::B);
	}
	if (sf::Joystick::isButtonPressed(0, 2)) {
		input.push_back(PressedButton::X);
	}
	if (sf::Joystick::isButtonPressed(0, 3)) {
		input.push_back(PressedButton::Y);
	}
	if (sf::Joystick::isButtonPressed(0, 4)) {
		input.push_back(PressedButton::L1);
	}
	if (sf::Joystick::isButtonPressed(0, 5)) {
		input.push_back(PressedButton::R1);
	}

	return input;
}



}
#ifndef WINDOW_KEYBOARDINPUT_H_
#define WINDOW_KEYBOARDINPUT_H_

#include <vector>

namespace window {

enum class PressedKey { arrowLeft, arrowRight, arrowUp, arrowDown, space, leftControl, rightControl, leftShift, A, D, S, W, Num0, Num1, Num2, Num3, Num4, Num6, Num8, any };

class KeyboardInput {
public:
	KeyboardInput();

	std::vector<PressedKey> getInput();
};

}

#endif
#ifndef WINDOW_JOYSTICKINPUT_H_
#define WINDOW_JOYSTICKINPUT_H_

#include <vector>

namespace window {

enum class PressedButton { leftX, rightX, upY, downY, leftZ, rightZ, upR, downR, leftU, rightU, upV, downV, hatLeftX, hatRightX, hatUpY, hatDownY, A, B, X, Y, L1, R1 };

class JoystickInput {
public:
	JoystickInput();

	std::vector<PressedButton> getInput();
};

}

#endif
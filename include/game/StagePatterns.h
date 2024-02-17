#ifndef GAME_STAGEPATTERNS_H_
#define GAME_STAGEPATTERNS_H_

#include <string>

namespace game {

// Legend:
// . - empty
// X - floor


std::string pattern1[13] = { "XXXXXXXXXXXXXXXXXXXXXXXXX",
							 ".........................",
							 ".........................",
							 ".........................",
							 "XXXXXXXXXXXXXXXXXXXXXXXXX",
							 ".........................",
							 ".........................",
							 ".........................",
							 "XXXXXXXXXXXXXXXXXXXXXXXXX",
							 ".........................",
							 ".........................",
							 ".........................",
							 "XXXXXXXXXXXXXXXXXXXXXXXXX" };

std::string emptyPattern[13] = { ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 ".........................",
								 "........................." };

std::string stefanPattern[13] = { ".........................",
								  "XXX.XXX.XXX.XXX.XXX.XX..X",
								  "X....X..X...X...X.X.XX..X",
								  "XXX..X..XXX.XXX.XXX.X.X.X",
								  "..X..X..X...X...X.X.X..XX",
								  "XXX..X..XXX.X...X.X.X..XX",
								  ".........................",
								  "XXX.XXX.XXX.XXX.XXX.XX..X",
								  "X....X..X...X...X.X.XX..X",
								  "XXX..X..XXX.XXX.XXX.X.X.X",
								  "..X..X..X...X...X.X.X..XX",
								  "XXX..X..XXX.X...X.X.X..XX",
								  "........................." };

}

#endif // !GAME_STAGEPATTERNS_H_

#ifndef GAME_STAGEPATTESNS_H_
#define GAME_STAGEPATTESNS_H_

#include <string>

namespace game {

// Legend:
// . - empty
// S - floor (stone)
// G - floor (grass)
// R - floor (brick)
// B - beholder location
// F - finish location

std::string pattern1[13] = { "SSSSSBSSSBSSSBSSSBSSSSSSS",
							 ".........................",
							 "..F......................",
							 ".........................",
							 "SSSSSSSSSSSSSSSSSSSSS..SS",
							 ".........................",
							 "....R.....R....R....R....",
							 ".........................",
							 "..SSSSSSSSSSSSSSSSSSSSSSS",
							 ".....R.....R.....R.......",
							 ".........................",
							 "..R.....R.....R.....R....",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG" };

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

std::string templatePattern[13] = { "SSSSSSSSSSSSSSSSSSSSSSSSS",
									".........................",
									".........................",
									".........................",
									"SSSSSSSSSSSSSSSSSSSSSSSSS",
									".........................",
									".........................",
									".........................",
									"SSSSSSSSSSSSSSSSSSSSSSSSS",
									".........................",
									".........................",
									".........................",
									"SSSSSSSSSSSSSSSSSSSSSSSSS" };

std::string stefanPattern[13] = { ".........................",
								  "SSS.SSS.SSS.SSS.SSS.SS..S",
								  "S....S..S...S...S.S.SS..S",
								  "SSS..S..SSS.SSS.SSS.S.S.S",
								  "..S..S..S...S...S.S.S..SS",
								  "SSS..S..SSS.S...S.S.S..SS",
								  ".........................",
								  "SSS.SSS.SSS.SSS.SSS.SS..S",
								  "S....S..S...S...S.S.SS..S",
								  "SSS..S..SSS.SSS.SSS.S.S.S",
								  "..S..S..S...S...S.S.S..SS",
								  "SSS..S..SSS.S...S.S.S..SS",
								  "........................." };

}

#endif // !GAME_STAGEPATTESNS_H_

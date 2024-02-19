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

std::string pattern2[13] = { "BSBSBSBSSSSBSSBSSBSSBSSBS",
							 ".......S.................",
							 ".......S.................",
							 "...S...S.............S...",
							 "...S...S...F.........S..."
							 "...S...SBSSBSSBSSBSSBS...",
							 "...S.....................",
							 "...S.....................",
							 "...SBSSBSSBSSBSSBSSBSSSSS",
							 ".........................",
							 ".........................",
							 ".........................",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG" };

std::string pattern3[13] = { "SSSSSSSBSBSBSBSBSBSSBSSBS",
							 ".....S.............S.....",
							 "B.BS.S.............S.....",
							 "...S.S......S......S.S...",
							 "...S.SB.B.B.S.B.B.BS.S..."
							 "...S.S......S......S.S...",
							 ".B.S.S......S......S.S...",
							 "...S.S......S......S.S...",
							 "...S.S.B.B.BSB.B.B.S.S...",
							 "...S.S......S......S.S...",
							 ".F.S........S......S.S...",
							 "...S........S........S...",
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

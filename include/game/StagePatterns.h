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

std::string pattern1[15] = { "SSSSSSSSSSSSSSSSSSSSSSSSS",
							 "SSSSSBSSSBSSSBSSSBSSSSSSS",
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
							 "GGGGGGGGGGGGGGGGGGGGGGGGG",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG" };

std::string pattern2[15] = { "SSSSSSSSSSSSSSSSSSSSSSSSS",
							 "BSBSBSBSSSSBSSBSSBSSBSSBS",
							 ".......S.................",
							 ".......S.................",
							 "...S...S.............S...",
							 "...S...S...F.........S...",
							 "...S...SBSSBSSBSSBSSBS...",
							 "...S.....................",
							 "...S.....................",
							 ".B.SBSSBSSBSSBSSBSSBSSSSS",
							 ".........................",
							 ".........................",
							 ".........................",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG" };

std::string pattern3[15] = { "SSSSSSSSSSSSSSSSSSSSSSSSS",
							 "SSSSSSSBSBSBSBSBSBSSBSSBS",
							 ".....S.............S.....",
							 "B.BS.S.............S.....",
							 "...S.S......S......S.S...",
							 "...S.SB.B.B.S.B.B.BS.S...",
							 "...S.S......S......S.S...",
							 ".B.S.S......S......S.S...",
							 "...S.S......S......S.S...",
							 "...S.S.B.B.BSB.B.B.S.S...",
							 "...S.S......S......S.S...",
							 ".F.S........S......S.S...",
							 "...S........S........S...",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG",
							 "GGGGGGGGGGGGGGGGGGGGGGGGG" };

std::string emptyPattern[15] = { ".........................",
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
								 ".........................",
								 ".........................",
								 "........................." };

std::string templatePattern[15] = { "SSSSSSSSSSSSSSSSSSSSSSSSS",
									"SSSSSSSSSSSSSSSSSSSSSSSSS",
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
									"SSSSSSSSSSSSSSSSSSSSSSSSS",
									"SSSSSSSSSSSSSSSSSSSSSSSSS" };

std::string stefanPattern[15] = { ".........................",
								  ".........................",
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
								  ".........................",
								  "........................." };

}

#endif // !GAME_STAGEPATTESNS_H_

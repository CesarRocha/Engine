//================================================================
//              Joint.cpp                                
//================================================================
#include "Joint.hpp"


//================================================================
Joint::Joint()
	: body1(0)
	, body2(0)
	, P(0.0f, 0.0f)
	, biasFactor(0.2f)
	, softness(0.0f)
{}

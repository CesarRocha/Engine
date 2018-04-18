//================================================================
//              Joint.hpp                                  
//================================================================
#pragma once
#ifndef _Joint_
#define _Joint_
#include "Vector2.hpp"
#include "Matrix2x2.hpp"
#include "RigidBody.hpp"

//================================================================
struct Joint
{
public:
	Joint();

private:
	Matrix2x2 M;
	Vector2 localAnchor1, localAnchor2;
	Vector2 r1, r2;
	Vector2 bias;
	Vector2 P;		// accumulated impulse
	RigidBody* body1;
	RigidBody* body2;
	float biasFactor;
	float softness;

};


#endif //!_Joint_
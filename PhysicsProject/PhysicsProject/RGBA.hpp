//================================================================
//              RGBA.hpp                                  
//================================================================
#pragma once
#ifndef _RGBA_
#define _RGBA_
#include "Vector3.hpp"
#include "Vector4.hpp"

//================================================================
class RGBA
{
public:
	RGBA();
	RGBA(float r, float g, float b);
	RGBA(unsigned char r, unsigned char g, unsigned char  b);
	RGBA(unsigned char r, unsigned char g, unsigned char  b, unsigned char a);

	Vector3 ToVec3();
	Vector4 ToVec4();

	//Primary Colors
	static RGBA WHITE;
	static RGBA BLACK;

	static RGBA RED;
	static RGBA GREEN;
	static RGBA BLUE;

	static RGBA ORANGE;
	static RGBA YELLOW;
	static RGBA PURPLE;

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};


#endif //!_RGBA_
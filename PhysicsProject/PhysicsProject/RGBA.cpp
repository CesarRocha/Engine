//================================================================
//              RGBA.cpp                                
//================================================================
#include "RGBA.hpp"


//================================================================
RGBA::RGBA()
	: r(255)
	, g(255)
	, b(255)
	, a(255)
{

}
RGBA::RGBA(float r, float g, float b)
	: r((unsigned char)(r * 255.0f))
	, g((unsigned char)(g * 255.0f))
	, b((unsigned char)(b * 255.0f))
	, a(255)
{

}
RGBA::RGBA(unsigned char r, unsigned char g, unsigned char b)
	: r(r)
	, g(g)
	, b(b)
	, a(255)
{

}
RGBA::RGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	: r(r)
	, g(g)
	, b(b)
	, a(a)
{

}


//================================================================
Vector3 RGBA::ToVec3()
{
	float ratio = 1.0f / 255;
	return Vector3(r * ratio, g * ratio, b * ratio);
}
Vector4 RGBA::ToVec4()
{
	float ratio = 1.0f / 255;
	return Vector4(r * ratio, g * ratio, b * ratio, a * ratio);
}


//================================================================
RGBA RGBA::WHITE((unsigned char)255, 255, 255, 255);
RGBA RGBA::BLACK	((unsigned char)	0,   0,   0, 255);

RGBA RGBA::RED	((unsigned char)  255,   0,   0, 255);
RGBA RGBA::GREEN	((unsigned char)	0, 255,   0, 255);
RGBA RGBA::BLUE	((unsigned char)	0,   0, 255, 255);

RGBA RGBA::ORANGE	((unsigned char)  255, 162,   0, 255);
RGBA RGBA::YELLOW	((unsigned char)  255, 255,   0, 255);
RGBA RGBA::PURPLE	((unsigned char)  128,   0, 128, 255);





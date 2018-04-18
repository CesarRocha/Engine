//================================================================
//              Vector2.cpp		                             
//================================================================
#include "Vector2.hpp"
#include <math.h>


//===================================================================================================
Vector2::Vector2()
	: x(0.0f)
	, y(0.0f)
{

}
Vector2::Vector2(float x_, float y_)
	: x(x_)
	, y(y_)
{

}


//===================================================================================================
float Vector2::Length() const
{
	return sqrtf(x * x + y * y);
}
float Vector2::Distance(const Vector2& position)
{
	float A = position.x - x;
	float B = position.y - y;
	return sqrtf(A*A + B*B);
}


//===================================================================================================
float Vector2::Dot(const Vector2& v)
{
	return x * v.x + y * v.y;
}


//===================================================================================================
const Vector2 Vector2::operator + (const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}
const Vector2 Vector2::operator - (const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}
const Vector2 Vector2::operator * (const float s) const
{
	return Vector2(x * s, y * s);
}
void Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
}
void Vector2::operator += (const Vector2& v)
{
	x += v.x;
	y += v.y;
}
void Vector2::operator -= (const Vector2& v)
{
	x -= v.x;
	y -= v.y;
}
void Vector2::operator *= (const float s)
{
	x *= s;
	y *= s;
}


//================================================================
const Vector2 operator * (float scale, const Vector2& vectorToScale)
{
	return vectorToScale * scale;
}


//================================================================
const Vector2 Vector2::ZERO(0.0f, 0.0f);

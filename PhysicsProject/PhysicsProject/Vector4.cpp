//================================================================
//              Vector4.cpp		                             
//================================================================
#include "Vector4.hpp"
#include <math.h>


//===================================================================================================
Vector4::Vector4()
	: x(0.0f)
	, y(0.0f)
	, z(0.0f)
	, w(0.0f)
{

}
Vector4::Vector4(float x_, float y_, float z_, float w_)
	: x(x_)
	, y(y_)
	, z(z_)
	, w(w_)
{

}


//===================================================================================================
float Vector4::Length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}
float Vector4::Distance(const Vector4& v)
{
	float X = v.x - x;
	float Y = v.y - y;
	float Z = v.y - z;
	float W = v.w * w;
	return sqrtf(X*X + Y*Y + Z*Z + W*W);
}


//===================================================================================================
float Vector4::Dot(const Vector4& v)
{
	return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w);
}


//===================================================================================================
const Vector4 Vector4::operator + (const Vector4& v) const
{
	return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}
const Vector4 Vector4::operator - (const Vector4& v) const
{
	return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}
const Vector4 Vector4::operator * (const float s) const
{
	return Vector4(x * s, y * s, z * s, w * s);
}
void Vector4::operator=(const Vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}
void Vector4::operator += (const Vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
void Vector4::operator -= (const Vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
void Vector4::operator *= (const float s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;
}


//================================================================
const Vector4 operator * (float scale, const Vector4& vectorToScale)
{
	return vectorToScale * scale;
}


//================================================================
const Vector4 Vector4::ZERO(0.0f, 0.0f, 0.0f, 0.0f);

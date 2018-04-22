//================================================================
//              Vector3.cpp		                             
//================================================================
#include "Vector3.hpp"
#include "MathUtilities.hpp"
#include "Matrix4x4.hpp"
#include <math.h>


//===================================================================================================
Vector3::Vector3()
	: x(0.0f)
	, y(0.0f)
	, z(0.0f)
{

}
Vector3::Vector3(float x_, float y_, float z_)
	: x(x_)
	, y(y_)
	, z(z_)
{
}


//===================================================================================================
float Vector3::Length() const
{
	return sqrtf(x * x + y * y + z * z);
}
float Vector3::LengthSquared()
{
	return (x*x + y*y + z*z);
}
float Vector3::Distance(const Vector3& v)
{
	float X = v.x - x;
	float Y = v.y - y;
	float Z = v.y - z;
	return sqrtf(X*X + Y*Y + Z*Z);
}
float Vector3::Dot(const Vector3& v)
{
	return (x * v.x) + (y * v.y) + (z * v.z);
}
Vector3 Vector3::Cross(const Vector3& v)
{
	return Vector3
	(
		y * v.z - v.y * z,
		z * v.x - v.z * x,
		x * v.y - v.x * y
	);
}
void Vector3::Normalize()
{
	float rSquared = Vector3::LengthSquared();

	if (rSquared != 0)
	{
		float length = Vector3::Length();
		float inverseLength = (1.0f / length);
		x = x*inverseLength;
		y = y*inverseLength;
		z = z*inverseLength;
	}
}


//================================================================
void Vector3::RotateOnAxis(RotateAxis axis, float degrees)
{
	Matrix4x4 rotator;
	if(axis ==	XAXIS)
		rotator = Matrix4x4::GetXRotator(degrees);
	if (axis == YAXIS)
		rotator = Matrix4x4::GetYRotator(degrees);
	if (axis == ZAXIS)
		rotator = Matrix4x4::GetZRotator(degrees);

	Vector3 postRotation = rotator * (*this);
	
	x = postRotation.x;
	y = postRotation.y;
	z = postRotation.z;
}
void Vector3::Scale(const Vector3& s)
{
	Matrix4x4 sm = Matrix4x4::GetScalingMatrix(s);
	*this = sm * (*this);
}


//===================================================================================================
const Vector3 Vector3::operator + (const Vector3& v)
{
	return Vector3(x + v.x, y + v.y, z + v.z);
}
const Vector3 Vector3::operator - (const Vector3& v)
{
	return Vector3(x - v.x, y - v.y, z - v.z);
}
const Vector3 Vector3::operator * (const float s)
{
	return Vector3(x * s, y * s, z * s);
}
const Vector3 Vector3::operator * (const Vector3& s)
{
	return Vector3(x * s.x, y * s.y, z * s.z);
}
void Vector3::operator = (const Vector3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}
void Vector3::operator += (const Vector3& v)
{
	x = x + v.x;
	y = y + v.y;
	z = z + v.z;
}
void Vector3::operator -= (const Vector3& v)
{
	x = x - v.x;
	y = y - v.y;
	z = z - v.z;
}
void Vector3::operator *= (const float s)
{
	x = x * s;
	y = y * s;
	z = z * s;
}


//================================================================
const Vector3 Vector3::ONE(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::ZERO(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::XUP(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::YUP(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::ZUP(0.0f, 0.0f, 1.0f);

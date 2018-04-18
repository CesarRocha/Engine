//================================================================
//              Vector3.hpp                                  
//================================================================
#pragma once
#ifndef _Vector3_
#define _Vector3_

struct Matrix4x4;
//================================================================
enum RotateAxis { XAXIS, YAXIS, ZAXIS };
struct Vector3
{
	Vector3();
	Vector3(float x_, float y_, float z_);


	float	Length() const;
	float	LengthSquared();
	float	Distance(const Vector3& v);
	float	Dot(const Vector3& v);
	Vector3 Cross(const Vector3& v);
	void	Normalize();
		
	void	RotateOnAxis(RotateAxis axis, float degrees);
	void	Scale(const Vector3& s);
	
	const Vector3 operator + (const Vector3& v);
	const Vector3 operator - (const Vector3& v);
	const Vector3 operator * (const Vector3& s);
	const Vector3 operator * (const float s);
	void operator = (const Vector3& v);
	void operator += (const Vector3& v);
	void operator -= (const Vector3& v);
	void operator *= (const float s);

	static const Vector3 ZERO;
	static const Vector3 XUP;
	static const Vector3 YUP;
	static const Vector3 ZUP;

	float x;
	float y;
	float z;
};

#endif //!_Vector3_
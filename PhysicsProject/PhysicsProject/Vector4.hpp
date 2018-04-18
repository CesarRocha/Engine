//================================================================
//              Vector4.hpp                                  
//================================================================
#pragma once
#ifndef _Vector4_
#define _Vector4_


//================================================================
struct Vector4
{
	Vector4();
	Vector4(float x_, float y_, float z_, float w_);

	float	Length() const;
	float	Distance(const Vector4& v);
	float	Dot(const Vector4& v);

	
	const Vector4 operator + (const Vector4& v) const;
	const Vector4 operator - (const Vector4& v) const;
	const Vector4 operator * (const float s) const;
	void operator = (const Vector4& v);
	void operator += (const Vector4& v);
	void operator -= (const Vector4& v);
	void operator *= (const float s);
	friend const Vector4 operator * (float scale, const Vector4& vectorToScale);

	static const Vector4 ZERO;

	float x;
	float y;
	float z;
	float w; //0 == direction  // 1 == position
};

#endif //!_Vector4_
//================================================================
//              Vector2.hpp                                  
//================================================================
#pragma once
#ifndef _Vector2_
#define _Vector2_


//================================================================
struct Vector2
{
	Vector2();
	Vector2(float x_, float y_);

	float	Length() const;
	float	Distance(const Vector2& position);
	float	Dot(const Vector2& v);

	
	const Vector2 operator + (const Vector2& v) const;
	const Vector2 operator - (const Vector2& v) const;
	const Vector2 operator * (const float s) const;
	void operator = (const Vector2& v);
	void operator += (const Vector2& v);
	void operator -= (const Vector2& v);
	void operator *= (const float s);
	friend const Vector2 operator * (float scale, const Vector2& vectorToScale);

	static const Vector2 ZERO;

	float x;
	float y;
};

#endif //!_Vector2_
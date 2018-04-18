//================================================================
//              Matrix2x2.hpp                                  
//================================================================
#pragma once
#ifndef _Matrix2x2_
#define _Matrix2x2_
#include "Vector2.hpp"
#include <math.h>
#include <float.h>
#include <assert.h>

//Column Major
//================================================================
struct Matrix2x2
{
	Matrix2x2();
	Matrix2x2(float angle);
	Matrix2x2(const Vector2& col1, const Vector2& col2);


	Matrix2x2 Transpose() const;
	Matrix2x2 Invert() const;

	Vector2 operator * (const Vector2& v);
	Matrix2x2 operator + (const Matrix2x2& m);
	Matrix2x2 operator * (const Matrix2x2& m);

	Vector2 m_iBasis;
	Vector2 m_jBasis;
};


#endif //!_Matrix2x2_
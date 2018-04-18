//================================================================
//              Matrix4x4.hpp                                  
//================================================================
#pragma once
#ifndef _Matrix4x4_
#define _Matrix4x4_
#include "Vector3.hpp"
#include "Vector4.hpp"
#include <math.h>
#include <float.h>
#include <assert.h>


//================================================================
struct Matrix4x4
{
	Matrix4x4();
	Matrix4x4(const Vector4& iBase_, const Vector4& jBase_, const Vector4& kBase_, const Vector4& trans_);
	Matrix4x4(const float c[]);

	void Scale(float s);
	void Rotate(RotateAxis axis, float degrees);
	void Translate(const Vector3& v);
	void Transpose();


	Matrix4x4 operator * (const Matrix4x4& m);
	Matrix4x4 operator + (const Matrix4x4& m);
	void operator = (const Matrix4x4& m);


	//Matrix-Vector operations
	Vector3 operator * (const Vector3& v);


	static Matrix4x4 GetXRotator(float degrees);
	static Matrix4x4 GetYRotator(float degrees);
	static Matrix4x4 GetZRotator(float degrees);
	static Matrix4x4 GetScalingMatrix(const Vector3& s);

private:
	Vector4 m_iBase, m_jBase, m_kBase, m_trans;
};


#endif //!_Matrix2x2_
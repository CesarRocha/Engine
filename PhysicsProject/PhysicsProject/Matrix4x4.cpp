//================================================================
//              Matrix4x4.cpp                                
//================================================================
#include "MathUtilities.hpp"
#include "Matrix4x4.hpp"


//================================================================
Matrix4x4::Matrix4x4()
{
	m_iBase.x = 1.0f;	m_jBase.x = 0.0f;	m_kBase.x = 0.0f;	m_trans.x = 0.0f;
	m_iBase.y = 0.0f;	m_jBase.y = 1.0f;	m_kBase.y = 0.0f;	m_trans.y = 0.0f;
	m_iBase.z = 0.0f;	m_jBase.z = 0.0f;	m_kBase.z = 1.0f;	m_trans.z = 0.0f;
	m_iBase.w = 0.0f;	m_jBase.w = 0.0f;	m_kBase.w = 0.0f;	m_trans.w = 1.0f;
}
Matrix4x4::Matrix4x4(const Vector4& iBase_, const Vector4& jBase_, const Vector4& kBase_, const Vector4& translation_)
{
	m_iBase = iBase_;	m_jBase = jBase_;	m_kBase = kBase_;	m_trans = translation_;
}
Matrix4x4::Matrix4x4(const float c[])
{
	m_iBase.x = c[0];	m_jBase.x = c[1];	m_kBase.x = c[2];	m_trans.x = c[3];
	m_iBase.y = c[4];	m_jBase.y = c[5];	m_kBase.y = c[6];	m_trans.y = c[7];
	m_iBase.z = c[8];	m_jBase.z = c[9];	m_kBase.z = c[10];	m_trans.z = c[11];
	m_iBase.w = c[12];	m_jBase.w = c[13];	m_kBase.w = c[14];	m_trans.w = c[15];
}



//================================================================
void Matrix4x4::Scale(float s)
{
	m_iBase.x *= s;
	m_jBase.y *= s;
	m_kBase.z *= s;
}
void Matrix4x4::Rotate(RotateAxis axis, float degrees)
{
	Matrix4x4 rotator;

	if (axis == XAXIS)
		rotator = GetXRotator(degrees);
	if (axis == YAXIS)
		rotator = GetYRotator(degrees);
	if (axis == ZAXIS)
		rotator = GetZRotator(degrees);

	*this = rotator * (*this);
}
void Matrix4x4::Translate(const Vector3& v)
{
	m_trans.x = v.x;
	m_trans.y = v.y;
	m_trans.z = v.z;
}
void Matrix4x4::Transpose()
{
	Matrix4x4 t = *this;
	m_iBase = Vector4(t.m_iBase.x, t.m_jBase.x, t.m_kBase.x, t.m_trans.x);
	m_jBase = Vector4(t.m_iBase.y, t.m_jBase.y, t.m_kBase.y, t.m_trans.y);
	m_kBase = Vector4(t.m_iBase.z, t.m_jBase.z, t.m_kBase.z, t.m_trans.z);
	m_trans = Vector4(t.m_iBase.w, t.m_jBase.w, t.m_kBase.w, t.m_trans.w);
}


//================================================================
Matrix4x4 Matrix4x4::GetXRotator(float degrees)
{
	float asRadians = ToRadians(degrees);
	float COS = cosf(asRadians);
	float SIN = sinf(asRadians);

	Matrix4x4 xRotator
	(
		Vector4(1.0f, 0.0f, 0.0f, 0.0f),
		Vector4(0.0f,  COS,  SIN, 0.0f),
		Vector4(0.0f, -SIN,  COS, 0.0f),
		Vector4(0.0f, 0.0f, 0.0f, 1.0f)
	);

	return xRotator;
}
Matrix4x4 Matrix4x4::GetYRotator(float degrees)
{
	float asRadians = ToRadians(degrees);
	float COS = cosf(asRadians);
	float SIN = sinf(asRadians);

	Matrix4x4 yRotator
	(
		Vector4( COS, 0.0f, -SIN, 0.0f),
		Vector4(0.0f, 1.0f, 0.0f, 0.0f),
		Vector4( SIN, 0.0f,  COS, 0.0f),
		Vector4(0.0f, 0.0f, 0.0f, 1.0f)
	);

	return yRotator;
}
Matrix4x4 Matrix4x4::GetZRotator(float degrees)
{
	float asRadians = ToRadians(degrees);
	float COS = cosf(asRadians);
	float SIN = sinf(asRadians);

	Matrix4x4 zRotator
	(
		Vector4( COS, -SIN, 0.0f, 0.0f),
		Vector4( SIN,  COS, 0.0f, 0.0f),
		Vector4(0.0f, 0.0f, 1.0f, 0.0f),
		Vector4(0.0f, 0.0f, 0.0f, 1.0f)
	);

	return zRotator;
}
Matrix4x4 Matrix4x4::GetScalingMatrix(const Vector3& s)
{
	return Matrix4x4
	(
		Vector4( s.x, 0.0f, 0.0f, 0.0f),
		Vector4(0.0f,  s.y, 0.0f, 0.0f),
		Vector4(0.0f, 0.0f,  s.z, 0.0f),
		Vector4(0.0f, 0.0f, 0.0f, 0.0f)
	);
}


//================================================================
Matrix4x4 Matrix4x4::operator + (const Matrix4x4& m)
{
	return Matrix4x4
	(
		m_iBase + m.m_iBase,
		m_jBase + m.m_jBase,
		m_kBase + m.m_kBase,
		m_trans + m.m_trans
	);
}
void Matrix4x4::operator = (const Matrix4x4& m)
{
	m_iBase = m.m_iBase;
	m_jBase = m.m_jBase;
	m_kBase = m.m_kBase;
	m_trans = m.m_trans;
}
Matrix4x4 Matrix4x4::operator * (const Matrix4x4& m)
{
	return Matrix4x4
	(
		Vector4 //iBase
		(
			(m_iBase.x * m.m_iBase.x) + (m_iBase.y * m.m_jBase.x) + (m_iBase.z * m.m_kBase.x) + (m_iBase.w * m.m_trans.x),
			(m_iBase.x * m.m_iBase.y) + (m_iBase.y * m.m_jBase.y) + (m_iBase.z * m.m_kBase.y) + (m_iBase.w * m.m_trans.y),
			(m_iBase.x * m.m_iBase.z) + (m_iBase.y * m.m_jBase.z) + (m_iBase.z * m.m_kBase.z) + (m_iBase.w * m.m_trans.z),
			(m_iBase.x * m.m_iBase.w) + (m_iBase.y * m.m_jBase.w) + (m_iBase.z * m.m_kBase.w) + (m_iBase.w * m.m_trans.w)
		),

		Vector4 //jBase
		(
			(m_jBase.x * m.m_iBase.x) + (m_jBase.y * m.m_jBase.x) + (m_jBase.z * m.m_kBase.x) + (m_jBase.w * m.m_trans.x),
			(m_jBase.x * m.m_iBase.y) + (m_jBase.y * m.m_jBase.y) + (m_jBase.z * m.m_kBase.y) + (m_jBase.w * m.m_trans.y),
			(m_jBase.x * m.m_iBase.z) + (m_jBase.y * m.m_jBase.z) + (m_jBase.z * m.m_kBase.z) + (m_jBase.w * m.m_trans.z),
			(m_jBase.x * m.m_iBase.w) + (m_jBase.y * m.m_jBase.w) + (m_jBase.z * m.m_kBase.w) + (m_jBase.w * m.m_trans.w)
		),

		Vector4 //kBase
		(
			(m_kBase.x * m.m_iBase.x) + (m_kBase.y * m.m_jBase.x) + (m_kBase.z * m.m_kBase.x) + (m_kBase.w * m.m_trans.x),
			(m_kBase.x * m.m_iBase.y) + (m_kBase.y * m.m_jBase.y) + (m_kBase.z * m.m_kBase.y) + (m_kBase.w * m.m_trans.y),
			(m_kBase.x * m.m_iBase.z) + (m_kBase.y * m.m_jBase.z) + (m_kBase.z * m.m_kBase.z) + (m_kBase.w * m.m_trans.z),
			(m_kBase.x * m.m_iBase.w) + (m_kBase.y * m.m_jBase.w) + (m_kBase.z * m.m_kBase.w) + (m_kBase.w * m.m_trans.w)
		),

		Vector4 //translation
		(
			(m_trans.x * m.m_iBase.x) + (m_trans.y * m.m_jBase.x) + (m_trans.z * m.m_kBase.x) + (m_trans.w * m.m_trans.x),
			(m_trans.x * m.m_iBase.y) + (m_trans.y * m.m_jBase.y) + (m_trans.z * m.m_kBase.y) + (m_trans.w * m.m_trans.y),
			(m_trans.x * m.m_iBase.z) + (m_trans.y * m.m_jBase.z) + (m_trans.z * m.m_kBase.z) + (m_trans.w * m.m_trans.z),
			(m_trans.x * m.m_iBase.w) + (m_trans.y * m.m_jBase.w) + (m_trans.z * m.m_kBase.w) + (m_trans.w * m.m_trans.w)
		)
	);
}
Vector3 Matrix4x4::operator * (const Vector3& v)
{
	return Vector3
	(
		(m_iBase.x * v.x) + (m_iBase.y * v.y) + (m_iBase.z * v.z) + (m_iBase.w * 1),
		(m_jBase.x * v.x) + (m_jBase.y * v.y) + (m_jBase.z * v.z) + (m_jBase.w * 1),
		(m_kBase.x * v.x) + (m_kBase.y * v.y) + (m_kBase.z * v.z) + (m_kBase.w * 1)
	);
}
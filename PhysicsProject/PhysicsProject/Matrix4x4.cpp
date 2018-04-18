//================================================================
//              Matrix4x4.cpp                                
//================================================================
#include "MathUtilities.hpp"
#include "Matrix4x4.hpp"


//================================================================
Matrix4x4::Matrix4x4()
{
	m_i.x = 1.0f;	m_j.x = 0.0f;	m_k.x = 0.0f;	m_t.x = 0.0f;
	m_i.y = 0.0f;	m_j.y = 1.0f;	m_k.y = 0.0f;	m_t.y = 0.0f;
	m_i.z = 0.0f;	m_j.z = 0.0f;	m_k.z = 1.0f;	m_t.z = 0.0f;
	m_i.w = 0.0f;	m_j.w = 0.0f;	m_k.w = 0.0f;	m_t.w = 1.0f;
}
Matrix4x4::Matrix4x4(const Vector4& iBase_, const Vector4& jBase_, const Vector4& kBase_, const Vector4& translation_)
{
	m_i = iBase_;	m_j = jBase_;	m_k = kBase_;	m_t = translation_;
}
Matrix4x4::Matrix4x4(const float c[])
{
	m_i.x = c[0];	m_j.x = c[1];	m_k.x = c[2];	m_t.x = c[3];
	m_i.y = c[4];	m_j.y = c[5];	m_k.y = c[6];	m_t.y = c[7];
	m_i.z = c[8];	m_j.z = c[9];	m_k.z = c[10];	m_t.z = c[11];
	m_i.w = c[12];	m_j.w = c[13];	m_k.w = c[14];	m_t.w = c[15];
}



//================================================================
void Matrix4x4::Scale(float s)
{
	m_i.x *= s;
	m_j.y *= s;
	m_k.z *= s;
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
	m_t.x = v.x;
	m_t.y = v.y;
	m_t.z = v.z;
}
void Matrix4x4::Transpose()
{
	Matrix4x4 t = *this;
	m_i = Vector4(t.m_i.x, t.m_j.x, t.m_k.x, t.m_t.x);
	m_j = Vector4(t.m_i.y, t.m_j.y, t.m_k.y, t.m_t.y);
	m_k = Vector4(t.m_i.z, t.m_j.z, t.m_k.z, t.m_t.z);
	m_t = Vector4(t.m_i.w, t.m_j.w, t.m_k.w, t.m_t.w);
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
		m_i + m.m_i,
		m_j + m.m_j,
		m_k + m.m_k,
		m_t + m.m_t
	);
}
void Matrix4x4::operator = (const Matrix4x4& m)
{
	m_i = m.m_i;
	m_j = m.m_j;
	m_k = m.m_k;
	m_t = m.m_t;
}
Matrix4x4 Matrix4x4::operator * (const Matrix4x4& m)
{
	return Matrix4x4
	(
		Vector4 //iBase
		(
			(m_i.x * m.m_i.x) + (m_i.y * m.m_j.x) + (m_i.z * m.m_k.x) + (m_i.w * m.m_t.x),
			(m_i.x * m.m_i.y) + (m_i.y * m.m_j.y) + (m_i.z * m.m_k.y) + (m_i.w * m.m_t.y),
			(m_i.x * m.m_i.z) + (m_i.y * m.m_j.z) + (m_i.z * m.m_k.z) + (m_i.w * m.m_t.z),
			(m_i.x * m.m_i.w) + (m_i.y * m.m_j.w) + (m_i.z * m.m_k.w) + (m_i.w * m.m_t.w)
		),

		Vector4 //jBase
		(
			(m_j.x * m.m_i.x) + (m_j.y * m.m_j.x) + (m_j.z * m.m_k.x) + (m_j.w * m.m_t.x),
			(m_j.x * m.m_i.y) + (m_j.y * m.m_j.y) + (m_j.z * m.m_k.y) + (m_j.w * m.m_t.y),
			(m_j.x * m.m_i.z) + (m_j.y * m.m_j.z) + (m_j.z * m.m_k.z) + (m_j.w * m.m_t.z),
			(m_j.x * m.m_i.w) + (m_j.y * m.m_j.w) + (m_j.z * m.m_k.w) + (m_j.w * m.m_t.w)
		),

		Vector4 //kBase
		(
			(m_k.x * m.m_i.x) + (m_k.y * m.m_j.x) + (m_k.z * m.m_k.x) + (m_k.w * m.m_t.x),
			(m_k.x * m.m_i.y) + (m_k.y * m.m_j.y) + (m_k.z * m.m_k.y) + (m_k.w * m.m_t.y),
			(m_k.x * m.m_i.z) + (m_k.y * m.m_j.z) + (m_k.z * m.m_k.z) + (m_k.w * m.m_t.z),
			(m_k.x * m.m_i.w) + (m_k.y * m.m_j.w) + (m_k.z * m.m_k.w) + (m_k.w * m.m_t.w)
		),

		Vector4 //translation
		(
			(m_t.x * m.m_i.x) + (m_t.y * m.m_j.x) + (m_t.z * m.m_k.x) + (m_t.w * m.m_t.x),
			(m_t.x * m.m_i.y) + (m_t.y * m.m_j.y) + (m_t.z * m.m_k.y) + (m_t.w * m.m_t.y),
			(m_t.x * m.m_i.z) + (m_t.y * m.m_j.z) + (m_t.z * m.m_k.z) + (m_t.w * m.m_t.z),
			(m_t.x * m.m_i.w) + (m_t.y * m.m_j.w) + (m_t.z * m.m_k.w) + (m_t.w * m.m_t.w)
		)
	);
}
Vector3 Matrix4x4::operator * (const Vector3& v)
{
	return Vector3
	(
		(m_i.x * v.x) + (m_i.y * v.y) + (m_i.z * v.z) + (m_i.w * 1),
		(m_j.x * v.x) + (m_j.y * v.y) + (m_j.z * v.z) + (m_j.w * 1),
		(m_k.x * v.x) + (m_k.y * v.y) + (m_k.z * v.z) + (m_k.w * 1)
	);
}
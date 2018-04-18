//================================================================
//              Matrix2x2.cpp                                
//================================================================
#include "Matrix2x2.hpp"


//================================================================
Matrix2x2::Matrix2x2()
{

}
Matrix2x2::Matrix2x2(const Vector2& iBasis, const Vector2& jBasis)
	: m_iBasis(iBasis)
	, m_jBasis(jBasis)
{

}
Matrix2x2::Matrix2x2(float angle)
{
	float c = cosf(angle), s = sinf(angle);
	m_iBasis.x = c; m_jBasis.x = -s;
	m_iBasis.y = s; m_jBasis.y = c;
}


//================================================================
Matrix2x2 Matrix2x2::Transpose() const
{
	return Matrix2x2(Vector2(m_iBasis.x, m_jBasis.x), Vector2(m_iBasis.y, m_jBasis.y));
}
Matrix2x2 Matrix2x2::Invert() const
{
	float a = m_iBasis.x, b = m_jBasis.x, c = m_iBasis.y, d = m_jBasis.y;
	Matrix2x2 B;
	float det = a * d - b * c;
	assert(det != 0.0f);
	det = 1.0f / det;
	B.m_iBasis.x = det * d;	B.m_jBasis.x = -det * b;
	B.m_iBasis.y = -det * c;	B.m_jBasis.y = det * a;
	return B;
}


//================================================================
Vector2 Matrix2x2::operator * (const Vector2& v)
{
	return Vector2(m_iBasis.x * v.x + m_jBasis.x * v.y, m_iBasis.y * v.x + m_jBasis.y * v.y);
}
Matrix2x2 Matrix2x2::operator + (const Matrix2x2& m)
{
	return Matrix2x2(m_iBasis + m.m_iBasis, m_jBasis + m.m_jBasis);
}
Matrix2x2 Matrix2x2::operator * (const Matrix2x2& m)
{
	Vector2 iBasis
	(
		(m_iBasis.x * m.m_iBasis.x) + (m_iBasis.y * m.m_jBasis.x),
		(m_iBasis.x * m.m_iBasis.y) + (m_iBasis.y * m.m_jBasis.y)
	);
	
	Vector2 jBasis
	(
		(m_jBasis.x * m.m_iBasis.x) + (m_jBasis.y * m.m_jBasis.x),
		(m_jBasis.x * m.m_iBasis.y) + (m_jBasis.y * m.m_jBasis.y)
	);
	return Matrix2x2(iBasis, jBasis);
}
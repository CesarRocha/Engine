//================================================================
//              PointLight.hpp                                  
//================================================================
#pragma once
#ifndef _PointLight_
#define _PointLight_
#include "LightBase.hpp"

//================================================================
class PointLight : public LightBase
{
public:
	PointLight()
	{

	}
	PointLight(Vector3 position, float constant, float linear, float quadratic, Vector3 ambient, Vector3 diffuse, Vector3 specular)
		: LightBase(ambient, diffuse, specular)
		, m_position(position)
		, m_constant(constant)
		, m_linear(linear)
		, m_quadratic(quadratic)
	{

	}

	void SetPointValues(Vector3 position, float constant, float linear, float quadratic)
	{
		m_position = position;
		m_constant = constant;
		m_linear = linear;
		m_quadratic = quadratic;
	}

	Vector3 m_position;
	float m_constant;
	float m_linear;
	float m_quadratic;
};


#endif //!_PointLight_
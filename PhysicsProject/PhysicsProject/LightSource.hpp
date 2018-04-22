//================================================================
//              LightSource.hpp                                  
//================================================================
#pragma once
#ifndef _LightSource_
#define _LightSource_
#include "DirectionalLight.hpp"
#include "PointLight.hpp"
#include "SpotLight.hpp"


//================================================================
class LightSource : public BaseLight
{
	enum ELIGHT_TYPE { DIRECTIONAL, POINT, SPOT };
public:
	LightSource()
	{
	}
	void SetBaseValues(Vector3 ambient, Vector3 diffuse, Vector3 specular)
	{
		m_ambient = ambient;
		m_diffuse = diffuse;
		m_specular = specular;
	}
	void CreateDirectionalLight(Vector3 direction)
	{
		m_direction = direction;
	}
	void CreatePointLight(Vector3 position, float constant, float linear, float quadratic)
	{
		m_position = position;
		m_constant = constant;
		m_linear = linear;
		m_quadratic = quadratic;
	}
	void CreateSpotLight(Vector3 position, Vector3 direction, float cutoff, float outerCutoff, float constant, float linear, float quadratic)
	{	
		m_position = position;
		m_direction = direction;
		m_cutoff = cutoff;
		m_outerCutoff = outerCutoff;
		m_constant = constant;
		m_linear = linear;
		m_quadratic = quadratic;
	}
	//Shared
	Vector3 m_position;
	Vector3 m_direction;
	
	//Base
	Vector3 m_ambient;
	Vector3 m_diffuse;
	Vector3 m_specular;

	//Point
	float m_constant;
	float m_linear;
	float m_quadratic;

	//SpotLight
	float m_cutoff;
	float m_outerCutoff;
};


#endif //!_LightSource_
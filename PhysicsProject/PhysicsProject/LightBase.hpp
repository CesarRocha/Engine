//================================================================
//              LightBase.hpp                                  
//================================================================
#pragma once
#ifndef _LightBase_
#define _LightBase_
#include "Vector3.hpp"

//================================================================
class LightBase
{
public:
	LightBase()
	{

	}
	LightBase(Vector3 ambient, Vector3 diffuse, Vector3 specular)
		: m_ambient(ambient)
		, m_diffuse(diffuse)
		, m_specular(specular)
	{

	}
	
	void SetBaseValues(Vector3 ambient, Vector3 diffuse, Vector3 specular)
	{
		m_ambient = ambient;
		m_diffuse = diffuse;
		m_specular = specular;
	}

	Vector3 m_ambient;
	Vector3 m_diffuse;
	Vector3 m_specular;
};


#endif //!_LightBase_
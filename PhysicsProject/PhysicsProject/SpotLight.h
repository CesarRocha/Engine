//================================================================
//              SpotLight.hpp                                  
//================================================================
#pragma once
#ifndef _SpotLight_
#define _SpotLight_
#include "LightBase.hpp"

//================================================================
class SpotLight : public LightBase
{
public:
	SpotLight()
	{

	}
	SpotLight(Vector3 position, Vector3 direction, float cutoff, Vector3 ambient, Vector3 diffuse, Vector3 specular)
		: LightBase(ambient, diffuse, specular)
		, m_position(position)
		, m_direction(direction)
		, m_cutoff(cutoff)
	{

	}

	void SetSpotValues(Vector3 position, Vector3 direction, float cutoff)
	{
		m_position = position;
		m_direction = direction;
		m_cutoff = cutoff;
	}
	
	Vector3 m_position;
	Vector3 m_direction;
	float m_cutoff;
};


#endif //!_SpotLight_
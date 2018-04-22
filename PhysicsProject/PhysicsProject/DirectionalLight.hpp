//================================================================
//              DirectionalLight.hpp                                  
//================================================================
#pragma once
#ifndef _DirectionLight_
#define _DirectionLight_
#include "BaseLight.hpp"


//================================================================
class DirectionalLight : virtual public BaseLight
{
public:
	DirectionalLight() 
	{
	}
	DirectionalLight(Vector3 direction, Vector3 ambient, Vector3 diffuse, Vector3 specular) 
		:BaseLight(ambient, diffuse, specular)
		, m_direction(direction) 
	{
	}

	void SetDirectionalValue(Vector3 direction) 
	{ 
		m_direction = direction; 
	}

private:
	Vector3 m_direction;
};


#endif //!_DirectionLight_
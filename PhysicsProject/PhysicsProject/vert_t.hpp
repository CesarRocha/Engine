//================================================================
//              vert_t.hpp                                  
//================================================================
#pragma once
#ifndef _vert_t_
#define _vert_t_
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "RGBA.hpp"


//================================================================
class vert_t
{
public:
	vert_t() 
	{ 
		m_position = Vector3::ZERO; 
	}
	
	vert_t(Vector3 position) 
	{ 
		m_position = position; 
	}
	vert_t(Vector3 position, RGBA color)
	{
		m_position = position;
		m_color = color;
	}	
	vert_t(Vector3 position, RGBA color, Vector2 uv)
	{
		m_position = position;
		m_color = color;
		m_uv = uv;
	}

	vert_t(float x, float y, float z) 
	{ 
		m_position.x = x; 
		m_position.y = y; 
		m_position.z = z; 
	}
	vert_t(float x, float y, float z, RGBA color)
		:vert_t(x, y, z)
	{
		m_color = color;
	}
	vert_t(float x, float y, float z, RGBA color, float u, float v)
		:vert_t(x, y, z, color)
	{
		m_uv.x = u;
		m_uv.y = v;
	}


public:
	Vector3 m_position;
	Vector2 m_uv;
	RGBA	m_color;
	
};


#endif //!_vert_t_
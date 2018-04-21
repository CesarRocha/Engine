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
	vert_t();
	
	vert_t(Vector3 position);
	vert_t(Vector3 position, Vector3 normal);
	vert_t(Vector3 position, Vector2 uv, Vector3 normal);
	vert_t(Vector3 position, RGBA color);
	vert_t(Vector3 position, RGBA color, Vector2 uv);
	
	void SetPosition(Vector3 position)	{ m_position = position; }
	void SetColor(RGBA color)			{ m_color = color; }
	void SetUV(Vector2 uv)				{ m_uv = uv; }
	void SetNormal(Vector3 normal)		{ m_normal = normal; }

public:

	Vector3 m_position;
	RGBA	m_color;
	Vector2 m_uv;
	Vector3 m_normal;
	
};


#endif //!_vert_t_
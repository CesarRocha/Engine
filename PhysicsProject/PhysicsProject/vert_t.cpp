//================================================================
//              vert_t.cpp                                
//================================================================
#include "vert_t.hpp"


//================================================================
vert_t::vert_t()
{
	m_position = Vector3::ZERO;
}

vert_t::vert_t(Vector3 position)
{
	SetPosition(position);
}
vert_t::vert_t(Vector3 position, Vector3 normal)
{
	SetPosition(position);
	SetNormal(normal);
}
vert_t::vert_t(Vector3 position, Vector2 uv, Vector3 normal)
{
	SetPosition(position);
	SetUV(uv);
	SetNormal(normal);
}
vert_t::vert_t(Vector3 position, RGBA color)
{
	SetPosition(position);
	SetColor(color);
}
vert_t::vert_t(Vector3 position, RGBA color, Vector2 uv)
{
	SetPosition(position);
	SetColor(color);
	SetUV(uv);
}


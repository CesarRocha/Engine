//================================================================
//              World.cpp                         
//================================================================
#include "World.hpp"
#include "Matrix4x4.hpp"
#include "Vector3.hpp"

namespace
{
	vert_t plane[] =
	{
		vert_t( 0.5f,  0.5f, 0.0f,   RGBA(1.0f, 0.0f, 0.0f),   1.0f, 1.0f),
		vert_t( 0.5f, -0.5f, 0.0f,   RGBA(0.0f, 1.0f, 0.0f),   1.0f, 0.0f),
		vert_t(-0.5f, -0.5f, 0.0f,  RGBA(0.0f, 0.0f, 1.0f),   0.0f, 0.0f),
		vert_t(-0.5f,  0.5f, 0.0f,  RGBA(1.0f, 1.0f, 0.0f),   0.0f, 1.0f)
	};

	vert_t cube[] = 
	{
		vert_t(-0.5f, -0.5f, -0.5f, RGBA::WHITE, 0.0f, 0.0),
		vert_t(0.5f, -0.5f, -0.5f,  RGBA::WHITE, 1.0f, 0.0),
		vert_t(0.5f,  0.5f, -0.5f,  RGBA::WHITE, 1.0f, 1.0),
		vert_t(0.5f,  0.5f, -0.5f,  RGBA::WHITE, 1.0f, 1.0),
		vert_t(-0.5f,  0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0),
		vert_t(-0.5f, -0.5f, -0.5f, RGBA::WHITE, 0.0f, 0.0),

		vert_t(-0.5f, -0.5f,  0.5f, RGBA::WHITE, 0.0f, 0.0f),
		vert_t(0.5f, -0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),
		vert_t(0.5f,  0.5f,  0.5f,  RGBA::WHITE, 1.0f, 1.0f),
		vert_t(0.5f,  0.5f,  0.5f,  RGBA::WHITE, 1.0f, 1.0f),
		vert_t(-0.5f,  0.5f,  0.5f, RGBA::WHITE, 0.0f, 1.0f),
		vert_t(-0.5f, -0.5f,  0.5f, RGBA::WHITE, 0.0f, 0.0f),

		vert_t(-0.5f,  0.5f,  0.5f, RGBA::WHITE, 1.0f, 0.0f),
		vert_t(-0.5f,  0.5f, -0.5f, RGBA::WHITE, 1.0f, 1.0f),
		vert_t(-0.5f, -0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0f),
		vert_t(-0.5f, -0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0f),
		vert_t(-0.5f, -0.5f,  0.5f, RGBA::WHITE, 0.0f, 0.0f),
		vert_t(-0.5f,  0.5f,  0.5f, RGBA::WHITE, 1.0f, 0.0f),

		vert_t(0.5f,  0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),
		vert_t(0.5f,  0.5f, -0.5f,  RGBA::WHITE, 1.0f, 1.0f),
		vert_t(0.5f, -0.5f, -0.5f,  RGBA::WHITE, 0.0f, 1.0f),
		vert_t(0.5f, -0.5f, -0.5f,  RGBA::WHITE, 0.0f, 1.0f),
		vert_t(0.5f, -0.5f,  0.5f,  RGBA::WHITE, 0.0f, 0.0f),
		vert_t(0.5f,  0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),

		vert_t(-0.5f, -0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0f),
		vert_t(0.5f, -0.5f, -0.5f,  RGBA::WHITE, 1.0f, 1.0f),
		vert_t(0.5f, -0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),
		vert_t(0.5f, -0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),
		vert_t(-0.5f, -0.5f,  0.5f, RGBA::WHITE, 0.0f, 0.0f),
		vert_t(-0.5f, -0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0f),

		vert_t(-0.5f,  0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0f),
		vert_t(0.5f,  0.5f, -0.5f,  RGBA::WHITE, 1.0f, 1.0f),
		vert_t(0.5f,  0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),
		vert_t(0.5f,  0.5f,  0.5f,  RGBA::WHITE, 1.0f, 0.0f),
		vert_t(-0.5f,  0.5f,  0.5f, RGBA::WHITE, 0.0f, 0.0f),
		vert_t(-0.5f,  0.5f, -0.5f, RGBA::WHITE, 0.0f, 1.0f)
	};

	unsigned int i[] =
	{
		0, 1, 3,
		1, 2, 3
	};
	float cm[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	Shader* primaryShader = nullptr;
	Shader* debugShader = nullptr;

	vert_t origin[] =
	{
		vert_t(0.0f, 0.0f, 0.0f, RGBA::WHITE, 0.0f, 0.0f)
	};

}


//================================================================
World::World()
{

}
World::World(Vector2 displaySize)
{

}


//================================================================
void World::StartUp()
{
	//primaryShader = new Shader("vert.vs", "frag.fs", plane, 4, i, 6);
	primaryShader = new Shader("vert.vs", "frag.fs", cube, 36);
	debugShader = new Shader("vert.vs", "debug.fs", origin, 1);
	debugShader->AddGeometryShader("debug.gs", POINT_S);
}


//===================================================================================================
void World::Update(float deltaTime)
{

}
void World::Render(GLSLRenderer* renderer)
{
	primaryShader->Render();
	debugShader->Render();
}

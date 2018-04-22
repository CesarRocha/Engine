//================================================================
//              World.cpp                         
//================================================================
#include "World.hpp"
#include "Matrix4x4.hpp"
#include "Vector3.hpp"
#include "MathUtilities.hpp"

namespace
{
	vert_t lightCube[] =
	{
		//Bottom
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		Vector2(0.0f,  0.0),		Vector3(0.0f,  0.0f, -1.0f)),
		vert_t(Vector3(0.5f, -0.5f, -0.5f),		Vector2(1.0f,  0.0),		Vector3(0.0f,  0.0f, -1.0f)),
		vert_t(Vector3(0.5f,  0.5f, -0.5f),		Vector2(1.0f,  1.0),		Vector3(0.0f,  0.0f, -1.0f)),
		vert_t(Vector3(0.5f,  0.5f, -0.5f),		Vector2(1.0f,  1.0),		Vector3(0.0f,  0.0f, -1.0f)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		Vector2(0.0f,  1.0),		Vector3(0.0f,  0.0f, -1.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		Vector2(0.0f,  0.0),		Vector3(0.0f,  0.0f, -1.0f)),		//Top
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		Vector2(0.0f, 0.0f),		Vector3(0.0f,  0.0f, 1.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(0.0f,  0.0f, 1.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		Vector2(1.0f, 1.0f),		Vector3(0.0f,  0.0f, 1.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		Vector2(1.0f, 1.0f),		Vector3(0.0f,  0.0f, 1.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		Vector2(0.0f, 1.0f),		Vector3(0.0f,  0.0f, 1.0f)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		Vector2(0.0f, 0.0f),		Vector3(0.0f,  0.0f, 1.0f)),		//Front
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		Vector2(1.0f, 0.0f),		Vector3(-1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		Vector2(1.0f, 1.0f),		Vector3(-1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		Vector2(0.0f, 1.0f),		Vector3(-1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		Vector2(0.0f, 1.0f),		Vector3(-1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		Vector2(0.0f, 0.0f),		Vector3(-1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		Vector2(1.0f, 0.0f),		Vector3(-1.0f,  0.0f,  0.0f)),		//Back
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(0.5f,  0.5f,  -0.5f),		Vector2(1.0f, 1.0f),		Vector3(1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		Vector2(0.0f, 1.0f),		Vector3(1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		Vector2(0.0f, 1.0f),		Vector3(1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		Vector2(0.0f, 0.0f),		Vector3(1.0f,  0.0f,  0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(1.0f,  0.0f,  0.0f)),		//Right 
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		Vector2(0.0f, 1.0f),		Vector3(0.0f, -1.0f,  0.0f)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		Vector2(1.0f, 1.0f),		Vector3(0.0f, -1.0f,  0.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(0.0f, -1.0f,  0.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(0.0f, -1.0f,  0.0f)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		Vector2(0.0f, 0.0f),		Vector3(0.0f, -1.0f,  0.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		Vector2(0.0f, 1.0f),		Vector3(0.0f, -1.0f,  0.0f)),		//Left
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		Vector2(0.0f, 1.0f),		Vector3(0.0f,  1.0f,  0.0f)),
		vert_t(Vector3(0.5f,  0.5f,  -0.5f),		Vector2(1.0f, 1.0f),		Vector3(0.0f,  1.0f,  0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(0.0f,  1.0f,  0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		Vector2(1.0f, 0.0f),		Vector3(0.0f,  1.0f,  0.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		Vector2(0.0f, 0.0f),		Vector3(0.0f,  1.0f,  0.0f)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		Vector2(0.0f, 1.0f),		Vector3(0.0f,  1.0f,  0.0f))
	};

	vert_t plane[] =
	{
		vert_t(Vector3( 0.5f,  0.5f, 0.0f),		RGBA(1.0f, 0.0f, 0.0f),		Vector2(1.0f, 1.0f)),
		vert_t(Vector3( 0.5f, -0.5f, 0.0f),		RGBA(0.0f, 1.0f, 0.0f),		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(-0.5f, -0.5f, 0.0f),		RGBA(0.0f, 0.0f, 1.0f),		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(-0.5f,  0.5f, 0.0f),		RGBA(1.0f, 1.0f, 0.0f),		Vector2(0.0f, 1.0f))
	};

	vert_t cube[] = 
	{
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f,  0.0)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		RGBA::WHITE,		Vector2(1.0f,  0.0)),
		vert_t(Vector3(0.5f,  0.5f,  -0.5f),		RGBA::WHITE,		Vector2(1.0f,  1.0)),
		vert_t(Vector3(0.5f,  0.5f,  -0.5f),		RGBA::WHITE,		Vector2(1.0f,  1.0)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f,  1.0)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f,  0.0)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		RGBA::WHITE,		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 1.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 1.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		RGBA::WHITE,		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		RGBA::WHITE,		Vector2(1.0f, 1.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		RGBA::WHITE,		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(0.5f,  0.5f,  -0.5f),		RGBA::WHITE,		Vector2(1.0f, 1.0f)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		RGBA::WHITE,		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(0.5f, -0.5f,  -0.5f),		RGBA::WHITE,		Vector2(1.0f, 1.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(0.5f, -0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(-0.5f, -0.5f,  0.5f),		RGBA::WHITE,		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(-0.5f, -0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f)),
		vert_t(Vector3(0.5f,  0.5f,  -0.5f),		RGBA::WHITE,		Vector2(1.0f, 1.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(0.5f,  0.5f,   0.5f),		RGBA::WHITE,		Vector2(1.0f, 0.0f)),
		vert_t(Vector3(-0.5f,  0.5f,  0.5f),		RGBA::WHITE,		Vector2(0.0f, 0.0f)),
		vert_t(Vector3(-0.5f,  0.5f, -0.5f),		RGBA::WHITE,		Vector2(0.0f, 1.0f))
	};

	unsigned int i[] =
	{
		0, 1, 3,
		1, 2, 3
	};
	float cm[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	Shader* box1 = nullptr;
	Shader* box2 = nullptr;
	Shader* debugShader = nullptr;

	vert_t origin[] =
	{
		vert_t(Vector3(0.0f, 0.0f, 0.0f), RGBA::WHITE, Vector2(0.0f, 0.0f))
	};

}


//================================================================
World::World()
{

}
World::World(Vector2 displaySize)
{

}

#include "LightingSystem.hpp"
//================================================================
void World::StartUp()
{
	box1 = new Shader("ex.vs", "ex.fs", lightCube, 36);
	box2 = new Shader("ex.vs", "ex.fs", lightCube, 36);
	Matrix4x4 m;
	m.Translate(Vector3(2.0f, 2.0f, 2.0f));
	box2->AddModelMatrix(m);
	debugShader = new Shader("debug.vs", "debug.fs", origin, 1);
	debugShader->AddGeometryShader("debug.gs", POINT_S);
	




	Texture* diffuseMap = Texture::CreateOrGetTexture("dat/container_diffuse.png");
	Texture* specularMap = Texture::CreateOrGetTexture("dat/container_specular.png");

	Material crate;
	crate.m_diffuseID = diffuseMap->GetTextureID();
	crate.m_specularID = specularMap->GetTextureID();
	crate.m_shininess = 32.0f;
	box1->SetMaterial(crate);
	box2->SetMaterial(crate);

	LightingSystem::g_theLightSystem->CreateDirectionalLight(Vector3(0.0f, 0.0f, -1.0f), Vector3::ZERO, RGBA::YELLOW.ToVec3(), Vector3(0.5f, 0.5f, 0.5f));
	LightingSystem::g_theLightSystem->CreatePointLight(Vector3(1.0f, 1.0f, 1.0f), 1.0f, 0.09f, 0.032f, Vector3::ZERO, Vector3(1.0f, 1.0f, 1.0f), Vector3(1.0f, 1.0f, 1.0f));
	LightingSystem::g_theLightSystem->CreateSpotLight(Vector3(-2.0f, 0.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f), cos(ToRadians(12.5f)), cos(ToRadians(15.0f)), 1.0f, 0.09, 0.032f, Vector3::ZERO, RGBA::GREEN.ToVec3(), Vector3(1.0f, 1.0f, 1.0f));
}

//===================================================================================================
void World::Update(float deltaTime)
{
}
void World::Render(GLSLRenderer* renderer)
{
	box1->Render();
	box2->Render();
	debugShader->Render();
}

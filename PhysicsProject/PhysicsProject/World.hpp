//================================================================
//              World.hpp                                  
//================================================================
#pragma once
#ifndef _World_
#define _World_
#include <vector>
#include "Camera3D.hpp"
#include "PhysicsEngineSAP.hpp"
#include "GLSLRenderer.hpp"


//================================================================
class World
{
public:
	World();
	World(Vector2 diplaySize);

	void	StartUp();

	void	Update(float deltaTime);
	void	Render(GLSLRenderer* renderer);

private:
};


#endif //!_World_
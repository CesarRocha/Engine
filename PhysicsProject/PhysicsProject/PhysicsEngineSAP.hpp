//================================================================
//              PhysicsEngine.hpp                                  
//================================================================
#pragma once
#ifndef _PhysicsEngine_
#define _PhysicsEngine_
#include "Vector2.hpp"
#include "Joint.hpp"
#include "RigidBody.hpp"
#include <vector>
#include <list>


//================================================================
class PhysicsEngineSAP
{
public:
	PhysicsEngineSAP();
	PhysicsEngineSAP(Vector2 gravity);
	
	void Update(float deltaTime);

	void Clear();
	void Add(RigidBody* pBody);
	void Add(Joint* pBody);

private:
	friend class World;
	std::vector<RigidBody*> m_bodies;
	std::vector<Joint*> m_joints;
	Vector2 m_gravity;
};

#endif //!_PhysicsEngine_


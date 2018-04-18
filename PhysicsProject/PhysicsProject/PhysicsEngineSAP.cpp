//================================================================
//              PhysicsEngine.cpp                                
//================================================================
#include "PhysicsEngineSAP.hpp"
#include <list>

//================================================================
PhysicsEngineSAP::PhysicsEngineSAP()
{

}
PhysicsEngineSAP::PhysicsEngineSAP(Vector2 gravity)
	:m_gravity(gravity)
{

}


//================================================================
void PhysicsEngineSAP::Update(float deltaTime)
{
	
}

//===================================================================================================
void PhysicsEngineSAP::Clear()
{
	m_bodies.clear();
	m_joints.clear();
}
void PhysicsEngineSAP::Add(RigidBody* pBody)
{
	m_bodies.push_back(pBody);
}
void PhysicsEngineSAP::Add(Joint* pJoint)
{
	m_joints.push_back(pJoint);
}


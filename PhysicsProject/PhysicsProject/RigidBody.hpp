//================================================================
//              PhysicsBody.hpp                                  
//================================================================
#pragma once
#ifndef _PhysicsBody_
#define _PhysicsBody_
#include "Vector2.hpp"





//================================================================
struct RigidBody
{
public:
	RigidBody();
	RigidBody(const Vector2& dimensionRadius, float mass);
	

private:
	Vector2 m_position;
	float	m_rotation;

	Vector2 m_velocity;
	float	m_angularVelocity;

	Vector2 m_force;
	float	m_torque;

	Vector2 m_dimensionRadius;

	float	m_friction;
	float	m_mass;
	float	m_invMass;
	float	m_I;
	float	m_invI;
};


#endif //!_PhysicsBody_
//================================================================
//              PhysicsBody.cpp                                
//================================================================
#include "RigidBody.hpp"
#include <float.h>

//================================================================
RigidBody::RigidBody()
	: m_position(Vector2(0.0f, 0.0f))
	, m_rotation(0.0f)
	, m_velocity(Vector2(0.0f, 0.0f))
	, m_angularVelocity(0.0f)
	, m_force(Vector2(0.0f, 0.0f))
	, m_torque(0.0f)
	, m_friction(0.2f)
	, m_dimensionRadius()
	, m_mass(FLT_MAX)
{

}
RigidBody::RigidBody(const Vector2& dimensionRadius, float mass)
	: m_position(Vector2(0.0f, 0.0f))
	, m_rotation(0.0f)
	, m_velocity(Vector2(0.0f, 0.0f))
	, m_angularVelocity(0.0f)
	, m_force(Vector2(0.0f, 0.0f))
	, m_torque(0.0f)
	, m_friction(0.2f)
	, m_dimensionRadius(dimensionRadius)
	, m_mass(mass)
{
}


//================================================================


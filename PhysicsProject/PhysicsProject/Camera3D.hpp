//================================================================
//              Camera3D.hpp                                  
//================================================================
#pragma once
#ifndef _Camera3D_
#define _Camera3D_
#include <map>
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix4x4.hpp"
#include "EulerAngles.hpp"


enum CameraMovement 
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class InputSystem;
//================================================================
class Camera3D
{
public:
	Camera3D();
	Camera3D(Vector3 position, float yaw, float pitch);
	static Camera3D* g_masterCamera;

	void UpdateVectors();

	void MoveDirection(CameraMovement direction);
	void UpdateMouseMovement();

	const Vector3 GetForwardVector() { return m_forward; }
	const Vector3 GetRightVector() { return m_right; }
	const Vector3 GetUpVector() { return m_up; }


	Vector3 m_position;
	EulerAngles m_orientation;

private:
	Vector3 m_worldUp;

	Vector3 m_forward;
	Vector3 m_right;
	Vector3 m_up;

	float m_movementSpeed;
	float m_mouseSensitivity;
};


#endif //!_Camera3D_
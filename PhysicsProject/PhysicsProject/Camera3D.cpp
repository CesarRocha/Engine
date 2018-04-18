//================================================================
//              Camera3D.cpp                                
//================================================================
#include "MathUtilities.hpp"
#include "Camera3D.hpp"
#include <Windows.h>

Camera3D* Camera3D::g_masterCamera = nullptr;
#define SPEED 0.1f
#define SENSITIVITY .04f
#include "OpenGLRenderer.hpp"
#include "InputSystem.hpp"
//================================================================
Camera3D::Camera3D()
	: m_position(Vector3::ZERO)
	, m_worldUp(Vector3::YUP)
	, m_movementSpeed(SPEED)
	, m_mouseSensitivity(SENSITIVITY)
{
	m_orientation.m_yaw = 0.0f;
	m_orientation.m_pitch = 0.0f;

	g_masterCamera = this;
	UpdateVectors();
}
Camera3D::Camera3D(Vector3 position, float yaw, float pitch)
	: m_position(position)
	, m_worldUp(Vector3::YUP)
	, m_movementSpeed(SPEED)
	, m_mouseSensitivity(SENSITIVITY)
{
	m_orientation.m_yaw = yaw;
	m_orientation.m_pitch = pitch;

	g_masterCamera = this;
	UpdateVectors();
}


//================================================================
void Camera3D::UpdateVectors()
{
	Vector3 forward;
	forward.x = cos(ToRadians(m_orientation.m_yaw)) * cos(ToRadians(m_orientation.m_pitch));
	forward.y = sin(ToRadians(m_orientation.m_yaw)) * cos(ToRadians(m_orientation.m_pitch));
	forward.z = sin(ToRadians(m_orientation.m_pitch));
	forward.Normalize();
	m_forward = forward;

	Vector3 right = m_forward.Cross(m_worldUp);
	right.Normalize();
	m_right = right;

	Vector3 up = m_right.Cross(m_forward);
	up.Normalize();
	m_up = up;
}

//================================================================
void Camera3D::MoveDirection(CameraMovement direction)
{
	if (direction == FORWARD)
		m_position += m_forward * m_movementSpeed;
	if (direction == BACKWARD)
		m_position -= m_forward * m_movementSpeed;
	if (direction == LEFT)
		m_position -= m_right * m_movementSpeed;
	if (direction == RIGHT)
		m_position += m_right * m_movementSpeed;
	if (direction == UP)
		m_position += m_up * m_movementSpeed;
	if (direction == DOWN)
		m_position -= m_up * m_movementSpeed;
	UpdateVectors();
}
void Camera3D::UpdateMouseMovement()
{
	POINT centerCursorPos = { 400, 300 };
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	SetCursorPos(centerCursorPos.x, centerCursorPos.y);
	Vector2 mouseDelta((float)cursorPos.x - (float)centerCursorPos.x, (float)cursorPos.y - (float)centerCursorPos.y);

	m_orientation.m_yaw   -= m_mouseSensitivity * mouseDelta.x;
	m_orientation.m_pitch += m_mouseSensitivity * mouseDelta.y;

	if (m_orientation.m_pitch > 89.0f)
		m_orientation.m_pitch = 89.0f;
	if (m_orientation.m_pitch < -89.0f)
		m_orientation.m_pitch = -89.0f;
}


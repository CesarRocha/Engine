//================================================================
//              Camera3D.cpp                                
//================================================================
#include "MathUtilities.hpp"
#include "Camera3D.hpp"
#include <Windows.h>

Camera3D* Camera3D::g_masterCamera = nullptr;
#define SPEED 1.0f
#define SENSITIVITY .04f


//================================================================
Camera3D::Camera3D()
	: m_position(Vector3::ZERO)
	, m_worldUp(Vector3::YUP)
	, m_movementSpeed(SPEED)
	, m_mouseSensitivity(SENSITIVITY)
{
	m_orientation.m_yawZ = 0.0f;
	m_orientation.m_pitchY = 0.0f;

	g_masterCamera = this;
	UpdateVectors();
}
Camera3D::Camera3D(Vector3 position, float yaw, float pitch)
	: m_position(position)
	, m_worldUp(Vector3::YUP)
	, m_movementSpeed(SPEED)
	, m_mouseSensitivity(SENSITIVITY)
{
	m_orientation.m_yawZ = yaw;
	m_orientation.m_pitchY = pitch;

	g_masterCamera = this;
	UpdateVectors();
}


//================================================================
void Camera3D::UpdateVectors()
{
	float cosPitch = cos(m_orientation.m_pitchY * DEG2RAD);
	float sinPitch = sin(m_orientation.m_pitchY * DEG2RAD);
	float cosYaw =	cos(m_orientation.m_yawZ   * DEG2RAD);
	float sinYaw =	sin(m_orientation.m_yawZ   * DEG2RAD);
	Vector3 direction(cosPitch * cosYaw, cosPitch * sinYaw, -sinPitch);
	direction.Normalize();
	m_forward = direction;

	Vector3 forwardVector = GetForwardVector();
	Vector3 rightVector = forwardVector.Cross(m_worldUp);
	rightVector.Normalize();
	m_right = rightVector;

	Vector3 upVector = rightVector.Cross(forwardVector);
	upVector.Normalize();
	m_up = upVector;
}


//================================================================
void Camera3D::MoveForwardCameraDirection(CameraMovement direction)
{
	UpdateVectors();

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
}
void Camera3D::StrafeCameraDirection(CameraMovement direction)
{
	float cameraYawDegrees = m_orientation.m_yawZ;
	float cameraYawRadians = ToRadians(cameraYawDegrees);
	Vector3 cameraForwardXY(cos(cameraYawRadians), sin(cameraYawRadians), 0.0f);
	Vector3 cameraLeftXY(cameraForwardXY.y, -cameraForwardXY.x, 0.0f);
	Vector3 cameraMoveVector(0.0f, 0.0f, 0.0f);

	if (direction == FORWARD)
		m_position += cameraForwardXY * m_movementSpeed;
	if (direction == BACKWARD)
		m_position -= cameraForwardXY * m_movementSpeed;
	if (direction == LEFT)
		m_position -= cameraLeftXY * m_movementSpeed;
	if (direction == RIGHT)
		m_position += cameraLeftXY * m_movementSpeed;
	if (direction == UP)
		m_position.z += m_movementSpeed;
	if (direction == DOWN)
		m_position.z -= m_movementSpeed;
}
void Camera3D::RotateCamera()
{
	//return;
	POINT centerCursorPos = { 400, 300 };
	POINT cursorPos;
	GetCursorPos(&cursorPos);
	SetCursorPos(centerCursorPos.x, centerCursorPos.y);
	Vector2 mouseDelta((float)cursorPos.x - (float)centerCursorPos.x, (float)cursorPos.y - (float)centerCursorPos.y);

	m_orientation.m_yawZ   -= (m_mouseSensitivity * mouseDelta.x);
	m_orientation.m_pitchY += (m_mouseSensitivity * mouseDelta.y);

	if (m_orientation.m_pitchY < -89.f)
		m_orientation.m_pitchY = -89.f;
	if (m_orientation.m_pitchY > 89.f)
		m_orientation.m_pitchY = 89.f;
}


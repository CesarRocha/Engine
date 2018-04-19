//================================================================
//              OpenGLRenderer.hpp                                  
//================================================================
#pragma once
#ifndef _OpenGLRenderer_
#define _OpenGLRenderer_
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "glut.h"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Matrix4x4.hpp"
#include "RGBA.hpp"
#include "vert_t.hpp"
#include "Texture.hpp"
#include "Camera3D.hpp"


//================================================================
class OpenGLRenderer
{
public:
	OpenGLRenderer();
	void	Startup(HWND windowHandle);
	void	Shutdown();

	//OpenGL Management 
	void	PreRender();
	void	PostRender();

	//Draw Commands (Vector)
	void	DrawText(Vector2 position, char* string, RGBA color = RGBA::PURPLE);
	void	DrawLine(Vector2 start, Vector2 end, RGBA color = RGBA::PURPLE);
	void	DrawLine(Vector3 start, Vector3 end, RGBA color = RGBA::PURPLE);
	void	DrawLineLoop(Vector2 v[], RGBA color = RGBA::PURPLE);

	//Draw Commands (vert)
	void	DrawLine(vert_t start, vert_t end, RGBA color = RGBA::PURPLE);
	void	DrawLineLoop(vert_t v[], RGBA color = RGBA::PURPLE);

	//Accessors
	float	GetDisplayWidth()  const { return m_displayWidth; }
	float	GetDisplayHeight() const { return m_displayHeight; }


	//Camera
	static Matrix4x4 CreateProjectionMatrix();
	static Matrix4x4 GetProjectionMatrix() { return m_projectionMatrix; }
	static Matrix4x4 CreateOrthoMatrix(float screenWidth, float screenHeight, float zFar, float zNear);
	static Matrix4x4 GetViewMatrix();

private:
	HWND	m_windowHandle;
	HDC		m_deviceContext;
	HGLRC   m_renderingContext;
	float   m_displayWidth;
	float   m_displayHeight;
	static	Matrix4x4 m_projectionMatrix;
};


#endif //!_OpenGLRenderer_
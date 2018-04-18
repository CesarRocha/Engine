//================================================================
//              TheApp.hpp                                  
//================================================================
#pragma once
#ifndef _TheApp_
#define _TheApp_
#include "GLSLRenderer.hpp"
#include "InputSystem.hpp"
#include "World.hpp"


//================================================================
class TheApp
{
public:
	TheApp();
	static TheApp* s_theApp;

	void	Startup(void* windowHandle);
	void	Run();
	void	Shutdown();

	void	ProcessInput();
	void	Update();
	void	Render();


private:
	void*					m_windowHandle;
	GLSLRenderer*			m_renderer;
	InputSystem*			m_inputSystem;
	Camera3D*				m_camera;
	World*					m_world;
	double					m_deltaTime;
};


#endif //!_TheApp_
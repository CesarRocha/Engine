//================================================================
//              TheApp.cpp                                
//================================================================
#include "TheApp.hpp"

namespace 
{
	bool strafeEnabled = true;
}

//================================================================
TheApp::TheApp()
	: m_renderer(NULL)
	, m_windowHandle(NULL)
	, m_deltaTime(1.0f / 60.0f)
{

}


//================================================================
void TheApp::Startup(void* windowHandle)
{

	//New Renderer
	m_windowHandle = windowHandle;
	m_renderer = new GLSLRenderer();
	if (m_renderer)
		m_renderer->Startup((HWND)windowHandle); 
	
	
	//New Input
	m_inputSystem = new InputSystem();
	if (m_inputSystem)
		m_inputSystem->Startup(windowHandle);
	
	//New Camera
	m_camera = new Camera3D();

	//New World
	m_world = new World();
	if (m_world)
		m_world->StartUp();

	
}
void TheApp::Run()
{
	while (!m_inputSystem->IsReadyToQuit())
	{
		ProcessInput();
		Update();
		Render();
	}
}
void TheApp::Shutdown()
{

}


//================================================================
void TheApp::ProcessInput()
{
	m_inputSystem->Update();

	//Exit App
	if (m_inputSystem->IsKeyDown(VK_ESCAPE))
		m_inputSystem->SetSystemQuit();

	if (m_inputSystem->WasKeyReleased('C'))
		strafeEnabled = !strafeEnabled;

	if (m_camera)
	{
		m_camera->RotateCamera();
		if (strafeEnabled)
		{			//Strafe
			if (m_inputSystem->IsKeyDown('W'))
				m_camera->StrafeCameraDirection(FORWARD);
			if (m_inputSystem->IsKeyDown('A'))
				m_camera->StrafeCameraDirection(LEFT);
			if (m_inputSystem->IsKeyDown('S'))
				m_camera->StrafeCameraDirection(BACKWARD);
			if (m_inputSystem->IsKeyDown('D'))
				m_camera->StrafeCameraDirection(RIGHT);
			if (m_inputSystem->IsKeyDown('E'))
				m_camera->StrafeCameraDirection(UP);
			if (m_inputSystem->IsKeyDown(VK_SPACE))
				m_camera->StrafeCameraDirection(DOWN);
		}
		else
		{
			//Forward Vector 
			if (m_inputSystem->IsKeyDown('W'))
				m_camera->MoveForwardCameraDirection(FORWARD);
			if (m_inputSystem->IsKeyDown('A'))
				m_camera->MoveForwardCameraDirection(LEFT);
			if (m_inputSystem->IsKeyDown('S'))
				m_camera->MoveForwardCameraDirection(BACKWARD);
			if (m_inputSystem->IsKeyDown('D'))
				m_camera->MoveForwardCameraDirection(RIGHT);
			if (m_inputSystem->IsKeyDown('E'))
				m_camera->MoveForwardCameraDirection(UP);
			if (m_inputSystem->IsKeyDown(VK_SPACE))
				m_camera->MoveForwardCameraDirection(DOWN);
		}
	}

}
void TheApp::Update()
{
	m_world->Update(m_deltaTime);
}


//================================================================
void TheApp::Render()
{
	m_renderer->PreRender();
	{
		//Render World
		if (m_world)
			m_world->Render(m_renderer);
	}
	m_renderer->PostRender();

}

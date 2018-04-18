//================================================================
//              TheApp.cpp                                
//================================================================
#include "TheApp.hpp"


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

#include "Utilities.hpp"
//================================================================
void TheApp::ProcessInput()
{
	m_inputSystem->Update();

	//Exit App
	if (m_inputSystem->IsKeyDown(VK_ESCAPE))
		m_inputSystem->SetSystemQuit();

	if (m_camera)
	{
		//m_camera->UpdateMouseMovement();
		if (m_inputSystem->IsKeyDown('W'))
			m_camera->MoveDirection(FORWARD);
		if (m_inputSystem->IsKeyDown('A'))
			m_camera->MoveDirection(LEFT);
		if (m_inputSystem->IsKeyDown('S'))
			m_camera->MoveDirection(BACKWARD);
		if (m_inputSystem->IsKeyDown('D'))
			m_camera->MoveDirection(RIGHT);
		if (m_inputSystem->IsKeyDown('E'))
			m_camera->MoveDirection(UP);
		if (m_inputSystem->IsKeyDown(VK_SPACE))
			m_camera->MoveDirection(DOWN);
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

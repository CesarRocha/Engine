//================================================================
//              InputSystem.cpp                                
//================================================================
#include "InputSystem.hpp"
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN
InputSystem* InputSystem::s_theInputSystem = nullptr;

LRESULT __stdcall WindowMessageProcessingFunction(HWND windowHandle, UINT messageID, WPARAM wParam, LPARAM lParam)
{
	if (InputSystem::s_theInputSystem)
	{
		switch (messageID)
		{
		case WM_KEYDOWN:
			InputSystem::s_theInputSystem->SetKeyState((int)wParam, true);			return 0;
		case WM_KEYUP:
			InputSystem::s_theInputSystem->SetKeyState((int)wParam, false);			return 0;


		case WM_LBUTTONDOWN:  //513
			InputSystem::s_theInputSystem->SetMouseState((int)wParam, true);		return 0;
		case WM_LBUTTONUP:    //514
			InputSystem::s_theInputSystem->SetMouseState((int)wParam + 1, false);	return 0;
		case WM_RBUTTONDOWN:  //516
			InputSystem::s_theInputSystem->SetMouseState((int)wParam, true);		return 0;
		case WM_RBUTTONUP:    //517
			InputSystem::s_theInputSystem->SetMouseState((int)wParam + 2, false);	return 0;


		case WM_CLOSE:
			InputSystem::s_theInputSystem->SetSystemQuit();							return 0;
		default: 
			break;
		}
	}
	return DefWindowProc(windowHandle, messageID, wParam, lParam);
}


//================================================================
InputSystem::InputSystem()
	: m_platformHandle(NULL)
	, m_previousAddress(0L)
	, m_isReadyToQuit(false)
{
}
InputSystem::~InputSystem()
{

}


//================================================================
void InputSystem::Startup(void* platformHandle)
{
	InputSystem::s_theInputSystem = this;

	m_platformHandle = platformHandle;
	m_previousAddress = SetWindowLong((HWND)platformHandle, GWL_WNDPROC, (long)& WindowMessageProcessingFunction);

	//Keyboard
	for (int i = 0; i < NUMBER_OF_VIRTUAL_KEYS; ++i)
	{
		m_keyStates[i].m_isDown = false;
		m_keyStates[i].m_wasReleased = false;
	}

	//Mouse
	for (unsigned int mouseIndex = 0; mouseIndex < NUMBER_OF_MOUSE_KEYS; mouseIndex++)
	{
		m_mouseStates[mouseIndex].m_isDown = false;
		m_mouseStates[mouseIndex].m_wasReleased = false;
	}
}
void InputSystem::Update()
{
	HWND myWindowHandle = (HWND)(m_platformHandle);
	MSG queuedMessage;

	for (int key = 0; key < NUMBER_OF_VIRTUAL_KEYS; ++key)
		m_keyStates[key].m_wasReleased = false;


	//Mouse
	for (unsigned int i = 0; i < NUMBER_OF_MOUSE_KEYS; i++)
		m_mouseStates[i].m_wasReleased = false;


	for (; ; )
	{
		BOOL messageWasFound = PeekMessage(&queuedMessage, myWindowHandle, 0, 0, PM_REMOVE);
		if (!messageWasFound)
			break;

		TranslateMessage(&queuedMessage);
		DispatchMessage(&queuedMessage);
	}
}
void InputSystem::Shutdown()
{
	SetWindowLong((HWND)m_platformHandle, GWL_WNDPROC, (long)& m_previousAddress);
}


//================================================================
void InputSystem::SetKeyState(int key, bool isPressedDown)
{
	if (m_keyStates[key].m_isDown && !isPressedDown)
		m_keyStates[key].m_wasReleased = true;


	if (key >= 0 && key < NUMBER_OF_VIRTUAL_KEYS)
		m_keyStates[key].m_isDown = isPressedDown;
}
bool InputSystem::WasKeyReleased(int key)
{
	if (key >= 0 && key < NUMBER_OF_VIRTUAL_KEYS)
		return m_keyStates[key].m_wasReleased;
	else
		return false;
}
bool InputSystem::IsKeyDown(int key)
{
	if (key >= 0 && key < NUMBER_OF_VIRTUAL_KEYS)
		return m_keyStates[key].m_isDown;
	else
		return false;
}


//================================================================
void InputSystem::SetMouseState(int mouseButton, bool isPressedDown)
{
	if (m_mouseStates[mouseButton].m_isDown == true && isPressedDown == false)
		m_mouseStates[mouseButton].m_wasReleased = true;

	if (mouseButton >= 0 && mouseButton < NUMBER_OF_MOUSE_KEYS)
		m_mouseStates[mouseButton].m_isDown = isPressedDown;
}
bool InputSystem::IsMouseDown(int mouseButton)
{
	if (mouseButton >= 0 && mouseButton < NUMBER_OF_MOUSE_KEYS)
		return m_mouseStates[mouseButton].m_isDown;
	else
		return false;
}
bool InputSystem::WasMouseReleased(int mouseButton)
{
	if (mouseButton >= 0 && mouseButton < NUMBER_OF_MOUSE_KEYS)
		return m_mouseStates[mouseButton].m_wasReleased;
	else
		return false;
}


//================================================================
bool InputSystem::IsReadyToQuit() const
{
	return m_isReadyToQuit;
}
void InputSystem::SetSystemQuit()
{
	m_isReadyToQuit = true;
}

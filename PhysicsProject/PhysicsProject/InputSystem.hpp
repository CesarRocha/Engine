//================================================================
//              InputSystem.hpp                                  
//================================================================
#pragma once
#ifndef _InputSystem_
#define _InputSystem_
#include "Vector2.hpp"

#define NUMBER_OF_VIRTUAL_KEYS 256
#define NUMBER_OF_MOUSE_KEYS 3


//================================================================
struct KeyState
{
	bool	m_isDown;
	bool	m_wasReleased;
};

struct MouseState
{
	bool	m_isDown;
	bool	m_wasReleased;
};

//================================================================
class InputSystem
{
public:
	InputSystem();
	~InputSystem();
	static InputSystem* s_theInputSystem;
	
	void		Startup(void* platformHandle);
	void		Update();
	void		Shutdown();

	//Keyboard
	void		SetKeyState(int key, bool isPressedDown);
	bool		WasKeyReleased(int key);
	bool		IsKeyDown(int key);

	//Mouse
	void		SetMouseState(int mouseButton, bool isPressedDown);
	bool		IsMouseDown(int mouseButton);
	bool		WasMouseReleased(int mouseButton);
	
	//System
	bool		IsReadyToQuit() const;
	void		SetSystemQuit();

private:
	void*		m_platformHandle;
	long		m_previousAddress;
	bool		m_isReadyToQuit;

	KeyState	m_keyStates[NUMBER_OF_VIRTUAL_KEYS];

	MouseState  m_mouseStates[NUMBER_OF_MOUSE_KEYS];
	Vector2		m_mousePosition;
};


#endif //!_InputSystem_
#include <string.h>
#include <assert.h>

#include "TheApp.hpp"
#include "World.hpp"

#define DISCARD_PARAMETER(p) (void)p
TheApp* TheApp::s_theApp = nullptr;


//================================================================
LRESULT __stdcall GameMessageProcessingFunction(HWND windowHandle, UINT messageID, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(windowHandle, messageID, wParam, lParam);
}

HWND CreateAppWindow(HINSTANCE thisAppInstance, int showCommand)
{
	WNDCLASSEXW windowDescription;
	memset(&windowDescription, 0, sizeof(WNDCLASSEXW));

	windowDescription.hbrBackground;
	windowDescription.cbSize = sizeof(WNDCLASSEXW);
	windowDescription.hInstance = thisAppInstance;
	windowDescription.lpszClassName = TEXT("Engine");
	windowDescription.lpfnWndProc = GameMessageProcessingFunction;
	windowDescription.style = CS_HREDRAW | CS_OWNDC | CS_VREDRAW;

	RegisterClassEx(&windowDescription);

	HWND desktopWindow = GetDesktopWindow();

	RECT windowRect;
	RECT desktopWindowRect;
	RECT workArea;

	DWORD windowsStyleFlags = WS_OVERLAPPEDWINDOW;
	DWORD windowsStyleFlagsEx = WS_EX_APPWINDOW;
	DWORD borderCase = WS_OVERLAPPEDWINDOW;


	GetClientRect(desktopWindow, &desktopWindowRect);
	AdjustWindowRectEx(&windowRect, windowsStyleFlags, false, windowsStyleFlagsEx);
	SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);

	windowRect.left		= workArea.left;
	windowRect.top		= workArea.top;
	windowRect.right	= workArea.right;
	windowRect.bottom	= workArea.bottom;
	

	HWND WindowHandle = CreateWindow(
		TEXT("Engine"),
		TEXT("Engine"),
		borderCase,
		windowRect.left,
		windowRect.top,
		windowRect.right,
		windowRect.bottom,
		NULL,
		NULL,
		thisAppInstance,
		NULL);

	if (WindowHandle)
	{
		ShowWindow(WindowHandle, showCommand);
		UpdateWindow(WindowHandle);
	}

	return WindowHandle;
}

int __stdcall WinMain(HINSTANCE thisAppInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	DISCARD_PARAMETER(hPrevInstance);
	DISCARD_PARAMETER(lpCmdLine);

	HWND myWindowHandle = CreateAppWindow(thisAppInstance, nShowCmd);

	TheApp::s_theApp = new TheApp();
	TheApp::s_theApp->Startup(myWindowHandle);
	TheApp::s_theApp->Run();
	TheApp::s_theApp->Shutdown();
}
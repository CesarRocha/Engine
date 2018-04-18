//================================================================
//              GLSLRenderer.hpp                                  
//================================================================
#pragma once
#ifndef _GLSLRenderer_
#define _GLSLRenderer_
#include "OpenGLRenderer.hpp"
#include "GLSLFunctionLibrary.hpp"
#include "Shader.hpp"
#include <vector>


//================================================================
class GLSLRenderer : public OpenGLRenderer
{
public:
	GLSLRenderer();
	void Startup(HWND windowHandle);
	void Update(float deltaSeconds);
	void Render();

	
private:
};

#endif //!_GLSLRenderer_
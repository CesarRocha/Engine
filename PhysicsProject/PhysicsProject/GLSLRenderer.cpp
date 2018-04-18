//================================================================
//              GLSLRenderer.cpp                                
//================================================================
#include "GLSLRenderer.hpp"
#include "Utilities.hpp"



//================================================================
GLSLRenderer::GLSLRenderer()
	:OpenGLRenderer()
{

}
void GLSLRenderer::Startup(HWND windowHandle)
{
	OpenGLRenderer::Startup(windowHandle);
	glGenBuffers				= (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
	glBindBuffer				= (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
 	glBufferData				= (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
 	glCreateShader				= (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
 	glShaderSource				= (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
 	glCompileShader				= (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
 	glGetShaderiv				= (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
 	glGetProgramiv				= (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
 	glGetShaderInfoLog			= (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
 	glCreateProgram				= (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
 	glAttachShader				= (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
 	glLinkProgram				= (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
 	glUseProgram				= (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
 	glDeleteShader				= (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
 	glGetAttribLocation			= (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
 	glVertexAttribPointer		= (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
	glEnableVertexAttribArray	= (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
 	glGenVertexArrays			= (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
 	glBindVertexArray			= (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
 	glGetUniformLocation		= (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");

// 	glDeleteBuffers				= (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers ");
// 	glGenerateMipmap			= (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
// 	glDetachShader				= (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
 	glDeleteProgram				= (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
// 	glProgramParameteri			= (PFNGLPROGRAMPARAMETERIPROC)wglGetProcAddress("glProgramParameteri");
// 	glGetProgramInfoLog			= (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
 	glGetUniformIndices			= (PFNGLGETUNIFORMINDICESPROC)wglGetProcAddress("glGetUniformIndices");
 	glGetActiveUniform			= (PFNGLGETACTIVEUNIFORMPROC)wglGetProcAddress("glGetActiveUniform");

 	glUniform1fv				= (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
 	glUniform2f					= (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
 	glUniform3f					= (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
 	glUniform4f					= (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
	glUniform1iv				= (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
 	glUniformMatrix4fv			= (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");

 	glDeleteVertexArrays		= (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
 	glActiveTexture				= (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
// 	glBindSampler				= (PFNGLBINDSAMPLERPROC)wglGetProcAddress("glBindSampler");
// 	glDeleteSamplers			= (PFNGLDELETESAMPLERSPROC)wglGetProcAddress("glDeleteSamplers");
// 	glGenSamplers				= (PFNGLGENSAMPLERSPROC)wglGetProcAddress("glGenSamplers");
// 	glSamplerParameteri			= (PFNGLSAMPLERPARAMETERIPROC)wglGetProcAddress("glSamplerParameteri");
// 	glBindFramebuffer			= (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
// 	glBlitFramebuffer			= (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
// 	glCheckFramebufferStatus	= (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
// 	glDeleteFramebuffers		= (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
// 	glFramebufferTexture		= (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
// 	glGenFramebuffers			= (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
// 	glBindFramebufferEXT		= (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebufferEXT");
// 	glCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatusEXT");
// 	glGetActiveAttrib			= (PFNGLGETACTIVEATTRIBPROC)wglGetProcAddress("glGetActiveAttrib");
// 	glPatchParameteri			= (PFNGLPATCHPARAMETERIPROC)wglGetProcAddress("glPatchParameteri");	
}


//================================================================
void GLSLRenderer::Update(float deltaSeconds)
{

}
void GLSLRenderer::Render()
{

}
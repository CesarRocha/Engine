//================================================================
//              GLSLFunctionLibrary.cpp                                
//================================================================
#include "GLSLFunctionLibrary.hpp"

PFNGLGENBUFFERSPROC					glGenBuffers = nullptr;
PFNGLBINDBUFFERPROC					glBindBuffer = nullptr;
PFNGLBUFFERDATAPROC					glBufferData = nullptr;
PFNGLCREATESHADERPROC				glCreateShader = nullptr;
PFNGLSHADERSOURCEPROC				glShaderSource = nullptr;
PFNGLCOMPILESHADERPROC				glCompileShader = nullptr;
PFNGLGETSHADERIVPROC				glGetShaderiv = nullptr;
PFNGLGETPROGRAMIVPROC				glGetProgramiv = nullptr;
PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog = nullptr;
PFNGLCREATEPROGRAMPROC				glCreateProgram = nullptr;
PFNGLATTACHSHADERPROC				glAttachShader = nullptr;
PFNGLLINKPROGRAMPROC				glLinkProgram = nullptr;
PFNGLUSEPROGRAMPROC					glUseProgram = nullptr;
PFNGLDELETESHADERPROC				glDeleteShader = nullptr;
PFNGLGETATTRIBLOCATIONPROC			glGetAttribLocation = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray = nullptr;
PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays = nullptr;
PFNGLBINDVERTEXARRAYPROC			glBindVertexArray = nullptr;
PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation = nullptr;

//PFNGLBINDATTRIBLOCATIONPROC		glBindAttribLocation = nullptr;
//PFNGLVALIDATEPROGRAMPROC			glValidateProgram = nullptr;
//PFNGLDELETEBUFFERSPROC			glDeleteBuffers = nullptr;
//PFNGLGENERATEMIPMAPPROC			glGenerateMipmap = nullptr;
//PFNGLDETACHSHADERPROC				glDetachShader = nullptr;
PFNGLDELETEPROGRAMPROC				glDeleteProgram = nullptr;
//PFNGLPROGRAMPARAMETERIPROC		glProgramParameteri = nullptr;
//PFNGLGETPROGRAMINFOLOGPROC		glGetProgramInfoLog = nullptr;
PFNGLGETUNIFORMINDICESPROC			glGetUniformIndices = nullptr;
PFNGLGETACTIVEUNIFORMPROC 			glGetActiveUniform = nullptr;

//PFNGLUNIFORM1FPROC				glUniform1f = nullptr;
PFNGLUNIFORM1FVPROC					glUniform1fv = nullptr;
PFNGLUNIFORM2FPROC					glUniform2f = nullptr;
PFNGLUNIFORM3FPROC					glUniform3f = nullptr;
PFNGLUNIFORM4FPROC					glUniform4f = nullptr;
//PFNGLUNIFORM3UIPROC				glUniform3ui = nullptr;
//PFNGLUNIFORM4UIPROC				glUniform4ui = nullptr;
//PFNGLUNIFORM1IPROC				glUniform1i = nullptr;
PFNGLUNIFORM1IVPROC					glUniform1iv = nullptr;
PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv = nullptr;

PFNGLDELETEVERTEXARRAYSPROC			glDeleteVertexArrays = nullptr;
PFNGLACTIVETEXTUREPROC				glActiveTexture = nullptr;
//PFNGLBINDSAMPLERPROC				glBindSampler = nullptr;
//PFNGLDELETESAMPLERSPROC			glDeleteSamplers = nullptr;
//PFNGLGENSAMPLERSPROC				glGenSamplers = nullptr;
//PFNGLSAMPLERPARAMETERIPROC		glSamplerParameteri = nullptr;
//PFNGLBINDFRAMEBUFFERPROC			glBindFramebuffer = nullptr;
//PFNGLBLITFRAMEBUFFERPROC			glBlitFramebuffer = nullptr;
//PFNGLCHECKFRAMEBUFFERSTATUSPROC	glCheckFramebufferStatus = nullptr;
//PFNGLDELETEFRAMEBUFFERSPROC		glDeleteFramebuffers = nullptr;
//PFNGLFRAMEBUFFERTEXTUREPROC		glFramebufferTexture = nullptr;
//PFNGLGENFRAMEBUFFERSPROC			glGenFramebuffers = nullptr;
//PFNGLBINDFRAMEBUFFEREXTPROC		glBindFramebufferEXT = nullptr;
//PFNGLCHECKFRAMEBUFFERSTATUSPROC	glCheckFramebufferStatusEXT = nullptr;
//PFNGLGETACTIVEATTRIBPROC			glGetActiveAttrib = nullptr;
//PFNGLPATCHPARAMETERIPROC			glPatchParameteri = nullptr;
//================================================================
//              GLSLFunctionLibrary.hpp                                  
//================================================================
#pragma once
#ifndef _GLSLFunctionLibrary_
#define _GLSLFunctionLibrary_
#include <Windows.h>
#include "glut.h"
#include "glext.h"


extern PFNGLGENBUFFERSPROC					glGenBuffers;
extern PFNGLBINDBUFFERPROC					glBindBuffer;
extern PFNGLBUFFERDATAPROC					glBufferData;
extern PFNGLCREATESHADERPROC				glCreateShader;
extern PFNGLSHADERSOURCEPROC				glShaderSource;
extern PFNGLCOMPILESHADERPROC				glCompileShader;
extern PFNGLGETSHADERIVPROC					glGetShaderiv;
extern PFNGLGETPROGRAMIVPROC				glGetProgramiv;
extern PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;
extern PFNGLCREATEPROGRAMPROC				glCreateProgram;
extern PFNGLATTACHSHADERPROC				glAttachShader;
extern PFNGLLINKPROGRAMPROC					glLinkProgram;
extern PFNGLUSEPROGRAMPROC					glUseProgram;
extern PFNGLDELETESHADERPROC				glDeleteShader;

extern PFNGLGETATTRIBLOCATIONPROC			glGetAttribLocation;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC		glEnableVertexAttribArray;
extern PFNGLVERTEXATTRIBPOINTERPROC			glVertexAttribPointer;
extern PFNGLGENVERTEXARRAYSPROC				glGenVertexArrays;
extern PFNGLBINDVERTEXARRAYPROC				glBindVertexArray;
extern PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation;

//extern PFNGLBINDATTRIBLOCATIONPROC		glBindAttribLocation;
//extern PFNGLDELETEBUFFERSPROC				glDeleteBuffers;
//extern PFNGLGENERATEMIPMAPPROC			glGenerateMipmap;
//extern PFNGLVALIDATEPROGRAMPROC			glValidateProgram;
//extern PFNGLDETACHSHADERPROC				glDetachShader;
extern PFNGLDELETEPROGRAMPROC				glDeleteProgram;
//extern PFNGLPROGRAMPARAMETERIPROC			glProgramParameteri;
//extern PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog;
extern PFNGLGETUNIFORMINDICESPROC			glGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMPROC 			glGetActiveUniform;

//extern PFNGLUNIFORM1FPROC					glUniform1f;
extern PFNGLUNIFORM1FVPROC					glUniform1fv;//
extern PFNGLUNIFORM2FPROC					glUniform2f;//
extern PFNGLUNIFORM3FPROC					glUniform3f;//
extern PFNGLUNIFORM4FPROC					glUniform4f;//
//extern PFNGLUNIFORM3UIPROC				glUniform3ui;
//extern PFNGLUNIFORM4UIPROC				glUniform4ui;
//extern PFNGLUNIFORM1IPROC					glUniform1i;
extern PFNGLUNIFORM1IVPROC					glUniform1iv;//
extern PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv;//



extern PFNGLDELETEVERTEXARRAYSPROC			glDeleteVertexArrays;
extern PFNGLACTIVETEXTUREPROC				glActiveTexture;
//extern PFNGLBINDSAMPLERPROC				glBindSampler;
//extern PFNGLDELETESAMPLERSPROC			glDeleteSamplers;
//extern PFNGLGENSAMPLERSPROC				glGenSamplers;
//extern PFNGLSAMPLERPARAMETERIPROC			glSamplerParameteri;
//extern PFNGLBINDFRAMEBUFFERPROC			glBindFramebuffer;
//extern PFNGLBLITFRAMEBUFFERPROC			glBlitFramebuffer;
//extern PFNGLCHECKFRAMEBUFFERSTATUSPROC	glCheckFramebufferStatus;
//extern PFNGLDELETEFRAMEBUFFERSPROC		glDeleteFramebuffers;
//extern PFNGLFRAMEBUFFERTEXTUREPROC		glFramebufferTexture;
//extern PFNGLGENFRAMEBUFFERSPROC			glGenFramebuffers;
//extern PFNGLBINDFRAMEBUFFEREXTPROC		glBindFramebufferEXT;
//extern PFNGLCHECKFRAMEBUFFERSTATUSPROC	glCheckFramebufferStatusEXT;
//extern PFNGLGETACTIVEATTRIBPROC			glGetActiveAttrib;
//extern PFNGLPATCHPARAMETERIPROC			glPatchParameteri;


#endif //!_GLSLFunctionLibrary_
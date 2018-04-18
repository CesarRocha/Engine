//================================================================
//              Shader.hpp                                  
//================================================================
#pragma once
#ifndef _Shader_
#define _Shader_
#include "OpenGLRenderer.hpp"
#include "GLSLFunctionLibrary.hpp"
#include <string>
#include <map>


//================================================================
class Shader
{
public:
	enum DrawType
	{
		ELEMENT,
		ARRAY
	};
	Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath);
	Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath, vert_t v[], int vertCount);
	Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath, vert_t v[], int vertCount, unsigned int i[], unsigned int indexCount);
	~Shader();
	void Render();


	void CompileShader(GLuint shader, std::string filePath);
	void LinkShader(GLuint program, GLuint vert, GLuint frag);
	bool QueryProgramStatus(GLuint toCheck, GLenum queryType);
	void BeginAttributeBindingAll();
	
	bool BindProgramAttribute(GLuint programID, const char* inName, GLint count, GLenum attributeType, GLboolean normalize, GLsizei stride, GLsizei offset);

	void SetVertData(vert_t v[], unsigned int vertCount);
	void SetVertIndexData(vert_t v[], unsigned int vertCount, unsigned int i[], unsigned int indexCount);

	bool BindUniformVec3(const char* uniformName, const Vector3 val);
	bool BindUniformVec4(const char* uniformName, const Vector4 val);
	bool BindUniformInt(const char* uniformName, const int& val);
	//bool BindUniformMat4(const char* uniformName, const Matrix4x4 val);
	bool BindUniformMat4(const char* uniformName, const Matrix4x4& val);
	bool BindUniformTexture(const char* uniformName, const unsigned int& textureID);


public:
	GLuint m_programID;
	GLuint m_VAO;
	int	   m_count;
	DrawType m_drawType;
};


#endif //!_Shader_
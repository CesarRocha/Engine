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


enum EShaderDrawMode { POINT_S, TRIANGLES };
//================================================================
class Shader
{
public:
	enum EShaderDrawType{ ELEMENT,	ARRAY };
	Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath);
	Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath, vert_t v[], int vertCount, unsigned int i[] = NULL, unsigned int indexCount = 0);


	void Render();
	void SetVertIndexData(vert_t v[], unsigned int vertCount, unsigned int i[] = NULL, unsigned int indexCount = 0);


	void CompileShader(GLuint shader, std::string filePath);
	void LinkShader(GLuint program, GLuint shader);
	bool QueryProgramStatus(GLuint toCheck, GLenum queryType);
	void AddGeometryShader(const GLchar* geoFilePath, EShaderDrawMode mode);
	

	bool BindProgramAttribute(GLuint programID, const char* inName, GLint count, GLenum attributeType, GLboolean normalize, GLsizei stride, GLsizei offset);
	bool BindUniformVec3(const char* uniformName, const Vector3 val);
	bool BindUniformVec4(const char* uniformName, const Vector4 val);
	bool BindUniformInt(const char* uniformName, const int& val);
	bool BindUniformFloat(const char* uniformName, const float& val);
	bool BindUniformMat4(const char* uniformName, const Matrix4x4& val);
	bool BindUniformTexture(const char* uniformName, const unsigned int& textureID);


	void AddModelMatrix(const Matrix4x4& m) { m_modelMatrix = m; }
public:
	GLuint		m_programID;
	GLuint		m_VAO;
	GLuint		m_VBO;
	int			m_count;
	EShaderDrawType	m_drawType;
	EShaderDrawMode	m_drawMode;
	Matrix4x4 m_modelMatrix;
};


#endif //!_Shader_
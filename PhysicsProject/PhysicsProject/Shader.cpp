//================================================================
//              Shader.cpp                                
//================================================================
#include "Shader.hpp"
#include "MathUtilities.hpp"
#include "Utilities.hpp"
#include "Matrix4x4.hpp"
#include "Camera3D.hpp"


Texture* texture1 = nullptr;
Texture* texture2 = nullptr;


//================================================================
Shader::Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath)
	: m_drawMode(TRIANGLES)
{
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	CompileShader(vertShader, vertFilePath);
	bool vertResult = QueryProgramStatus(vertShader, GL_COMPILE_STATUS);


	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	CompileShader(fragShader, fragmentFilePath);
	bool fragResult = QueryProgramStatus(fragShader, GL_COMPILE_STATUS);


	int program = glCreateProgram();
	m_programID = program;


	bool linkResult = false;
	Shader::LinkShader(program, vertShader);
	linkResult = Shader::QueryProgramStatus(program, GL_LINK_STATUS);
	Shader::LinkShader(program, fragShader);
	linkResult = Shader::QueryProgramStatus(program, GL_LINK_STATUS);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	//texture1 = Texture::CreateOrGetTexture("dat/test.png");
	texture1 = Texture::CreateOrGetTexture("dat/brick_diffuse.jpg");
	texture2 = Texture::CreateOrGetTexture("dat/brick_normal.jpg");
}
Shader::Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath, vert_t v[], int vertCount, unsigned int i[], unsigned int indexCount)
	: Shader(vertFilePath, fragmentFilePath)
{
	SetVertIndexData(v, vertCount, i, indexCount);
}


//================================================================
void Shader::Render()
{
	glUseProgram(m_programID);
	

	bool bindResult = false;
	unsigned int diffuseID = texture1->GetTextureID();
	unsigned int normalID = texture2->GetTextureID();

	bindResult = BindUniformTexture("gDiffuseMap", diffuseID);
	bindResult = BindUniformTexture("gNormalMap", normalID);

	Matrix4x4 model = m_modelMatrix;
	Matrix4x4 view = OpenGLRenderer::GetViewMatrix();
	Matrix4x4 proj = OpenGLRenderer::GetProjectionMatrix();

	bindResult = BindUniformMat4("gModel", model);
	bindResult = BindUniformMat4("gView", view);
	bindResult = BindUniformMat4("gProj", proj);

	bindResult = BindUniformVec3("gCameraPos", Camera3D::g_masterCamera->m_position);
	bindResult = BindUniformVec3("gLightPos", Vector3(2.0f, 2.0f, 2.0f)); //TEMP
	bindResult = BindUniformVec4("gLightColor", Vector4(1.0f, 1.0f, 1.0f, 1.0f));
	bindResult = BindUniformVec4("gAmbientColor", Vector4(0.1f, 0.1f, 0.1f, 1.0f));
	bindResult = BindUniformInt("gSpecShineStrength", 256);
	


	glBindVertexArray(m_VAO);
	if (m_drawType == ELEMENT)
	{
		glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, 0);
	}
	else
	{
		if (m_drawMode == TRIANGLES)
			glDrawArrays(GL_TRIANGLES, 0, m_count);
		if (m_drawMode == POINT_S)
			glDrawArrays(GL_POINTS, 0, m_count);
	}
}


//================================================================
void Shader::CompileShader(GLuint shader, std::string filePath)
{
	char* source = ReadFile(filePath);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
}
void Shader::LinkShader(GLuint program, GLuint shader)
{
	glAttachShader(program, shader);
	glLinkProgram(program);
}
bool Shader::BindProgramAttribute(GLuint programID, const char* inName, GLint count, GLenum attributeType, GLboolean normalize, GLsizei stride, GLsizei offset)
{
	GLint location = glGetAttribLocation(programID, inName);

	if (location != -1) //Attributes not found result in -1
	{
		glVertexAttribPointer(location, count, attributeType, normalize, stride, (GLvoid*)offset);
		glEnableVertexAttribArray(location);
		return true;
	}
	return false;
}
bool Shader::QueryProgramStatus(GLuint toCheck, GLenum queryType)
{
	int  queryResultSuccess;
	if(queryType == GL_COMPILE_STATUS)
		glGetShaderiv(toCheck, queryType, &queryResultSuccess);
	if (queryType == GL_LINK_STATUS)
		glGetProgramiv(toCheck, queryType, &queryResultSuccess);

	if (queryResultSuccess == GL_FALSE)
	{
		char infoLog[512];
		glGetShaderInfoLog(toCheck, 512, NULL, infoLog);
		ConsolePrintf(infoLog);
		return false;
	}
	return true;
}


//================================================================
void Shader::SetVertIndexData(vert_t v[], unsigned int vertCount, unsigned int i[], unsigned int indexCount)
{
	//Create buffer
	GLuint VBO;
	glGenBuffers(1, &VBO);
	int arrayBufferSize = vertCount * sizeof(vert_t);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, arrayBufferSize, v, GL_STATIC_DRAW);
	m_VBO = VBO;


	//Bind object
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	m_VAO = VAO;


	//Set shader draw info
	m_drawType = ARRAY;
	m_count = vertCount;


	//If indexed, create EBO
	if (i != NULL)
	{
		GLuint EBO;
		glGenBuffers(1, &EBO);
		int elemBufferSize = indexCount * sizeof(unsigned int);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemBufferSize, i, GL_STATIC_DRAW);
		m_drawType = ELEMENT;
		m_count = indexCount;
	}

	//Bind data
	bool bindResult = false;
	bindResult = Shader::BindProgramAttribute(m_programID, "inPos", 3, GL_FLOAT, GL_FALSE, sizeof(vert_t), offsetof(vert_t, m_position));
	bindResult = Shader::BindProgramAttribute(m_programID, "inUV", 2, GL_FLOAT, GL_FALSE, sizeof(vert_t), offsetof(vert_t, m_uv));
	bindResult = Shader::BindProgramAttribute(m_programID, "inColor", 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(vert_t), offsetof(vert_t, m_color));
	bindResult = Shader::BindProgramAttribute(m_programID, "inNormal", 3, GL_FLOAT, GL_TRUE, sizeof(vert_t), offsetof(vert_t, m_normal));
}
void Shader::AddGeometryShader(const GLchar* geoFilePath, EShaderDrawMode mode)
{
	GLuint geoShader = glCreateShader(GL_GEOMETRY_SHADER);
	CompileShader(geoShader, geoFilePath);
	bool geoResult = QueryProgramStatus(geoShader, GL_COMPILE_STATUS);
	Shader::LinkShader(m_programID, geoShader);
	bool linkResult = Shader::QueryProgramStatus(m_programID, GL_LINK_STATUS);

	m_drawMode = mode;
}


//================================================================
bool Shader::BindUniformVec3(const char* uniformName, const Vector3 val)
{
	GLint loc = glGetUniformLocation(m_programID, uniformName);
	if (loc < 0)
		return false;

	glUniform3f(loc, val.x, val.y, val.z);
	return true;
}
bool Shader::BindUniformVec4(const char* uniformName, const Vector4 val)
{
	GLint loc = glGetUniformLocation(m_programID, uniformName);
	if (loc < 0)
		return false;

	glUniform4f(loc, val.x, val.y, val.z, val.w);
	return true;
}
bool Shader::BindUniformInt(const char* uniformName, const int& val)
{
	GLint loc = glGetUniformLocation(m_programID, uniformName);
	if (loc < 0)
		return false;

	glUniform1iv(loc, 1, &val);
	return true;
}
bool Shader::BindUniformFloat(const char* uniformName, const float& val)
{
	GLint loc = glGetUniformLocation(m_programID, uniformName);
	if (loc < 0)
		return false;

	glUniform1fv(loc, 1, &val);
	return true;
}
bool Shader::BindUniformMat4(const char* uniformName, const Matrix4x4& val)
{
	GLint loc = glGetUniformLocation(m_programID, uniformName);
	if (loc < 0)
		return false;

	GLuint index;
	glGetUniformIndices(m_programID, 1, &uniformName, &index);
	if (index >= 0)
	{
		GLint count;
		GLenum type;
		glGetActiveUniform(m_programID, index, 0, NULL, &count, &type, NULL);
		assert(type == GL_FLOAT_MAT4);
	}

	glUniformMatrix4fv(loc, 1, GL_FALSE, (GLfloat*)&val);
	return true;
}
bool Shader::BindUniformTexture(const char* uniformName, const unsigned int& textureID)
{
	GLint loc = glGetUniformLocation(m_programID, uniformName);
	if (loc < 0)
		return false;

	glBindTexture(GL_TEXTURE_2D, textureID);
	return true;
}




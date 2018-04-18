//================================================================
//              Shader.cpp                                
//================================================================
#include "Shader.hpp"
#include "MathUtilities.hpp"
#include "Utilities.hpp"
#include "Matrix4x4.hpp"


Texture* texture1 = nullptr;
Texture* texture2 = nullptr;
//================================================================
Shader::Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath)
{
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	CompileShader(vertShader, vertFilePath);
	bool vertResult = QueryProgramStatus(vertShader, GL_COMPILE_STATUS);


	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	CompileShader(fragShader, fragmentFilePath);
	bool fragResult = QueryProgramStatus(fragShader, GL_COMPILE_STATUS);


	int program = glCreateProgram();
	Shader::LinkShader(program, vertShader, fragShader);
	bool linkResult = Shader::QueryProgramStatus(program, GL_LINK_STATUS);

	if (linkResult)
		m_programID = program;

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}
Shader::Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath, vert_t v[], int vertCount)
	:Shader(vertFilePath, fragmentFilePath)
{
	SetVertData(v, vertCount);
	//texture1 = Texture::CreateOrGetTexture("dat/Pebbles_003_COLOR.jpg");
	//texture2 = Texture::CreateOrGetTexture("dat/Pebbles_003_NRM.jpg");
	texture1 = Texture::CreateOrGetTexture("dat/test.png");
	texture2 = Texture::CreateOrGetTexture("dat/brick_normal.jpg");
}
Shader::Shader(const GLchar* vertFilePath, const GLchar* fragmentFilePath, vert_t v[], int vertCount, unsigned int i[], unsigned int indexCount)
	: Shader(vertFilePath, fragmentFilePath)
{
	SetVertIndexData(v, vertCount, i, indexCount);
	texture1 = Texture::CreateOrGetTexture("dat/test.png");
	//texture2 = Texture::CreateOrGetTexture("dat/Pebbles_003_NRM.jpg");
	//texture1 = Texture::CreateOrGetTexture("dat/happy.jpg");
	texture2 = Texture::CreateOrGetTexture("dat/brick_normal.jpg");
}
Shader::~Shader()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteProgram(m_programID);
}

#include "Camera3D.hpp"
//================================================================
void Shader::Render()
{
	glUseProgram(m_programID);

	bool bindResult = false;
	unsigned int diffuseID = texture1->GetTextureID();
	unsigned int normalID = texture2->GetTextureID();
	
	bindResult = BindUniformTexture("gDiffuseMap", diffuseID);
	bindResult = BindUniformTexture("gNormalMap", normalID);
	
	Matrix4x4 model;
	Matrix4x4 view;
	Matrix4x4 proj;

 	Vector3 pos			= Camera3D::g_masterCamera->m_position;
 	Vector3 forward		= Camera3D::g_masterCamera->GetForwardVector();
 	Vector3 up			= Camera3D::g_masterCamera->GetUpVector();
 	Vector3 right		= Camera3D::g_masterCamera->GetRightVector();

	proj = OpenGLRenderer::CreateProjectionMatrix(60.0f, (16.0f / 9.0f), 0.1f, 15000.0f);
	view = OpenGLRenderer::CreateLookAtMatrix(right, up, forward, pos);

	bindResult = BindUniformMat4("gModel", model);
	bindResult = BindUniformMat4("gView", view);
	bindResult = BindUniformMat4("gProj", proj);


	glBindVertexArray(m_VAO);		
	if (m_drawType == ELEMENT)
		glDrawElements(GL_TRIANGLES, m_count, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, m_count);
}


//================================================================
void Shader::CompileShader(GLuint shader, std::string filePath)
{
	char* source = ReadFile(filePath);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
}
void Shader::LinkShader(GLuint program, GLuint vert, GLuint frag)
{
	glAttachShader(program, vert);
	glAttachShader(program, frag);
	glLinkProgram(program);
}
void Shader::BeginAttributeBindingAll()
{
	bool bindResult = false;
	bindResult = Shader::BindProgramAttribute(m_programID, "inPos", 3, GL_FLOAT, GL_FALSE, sizeof(vert_t), offsetof(vert_t, m_position));
	bindResult = Shader::BindProgramAttribute(m_programID, "inUV", 2, GL_FLOAT, GL_FALSE, sizeof(vert_t), offsetof(vert_t, m_uv));
	bindResult = Shader::BindProgramAttribute(m_programID, "inColor", 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(vert_t), offsetof(vert_t, m_color));
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
void Shader::SetVertData(vert_t v[], unsigned int vertCount)
{
	GLuint VBO;
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	int bufferSize = vertCount * sizeof(vert_t);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, v, GL_STATIC_DRAW);

	BeginAttributeBindingAll();

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	m_VAO = VAO;
	m_drawType = ARRAY;
	m_count = vertCount;
}
void Shader::SetVertIndexData(vert_t v[], unsigned int vertCount, unsigned int i[], unsigned int indexCount)
{
	GLuint VBO;
	GLuint VAO;
	GLuint EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	int arrayBufferSize = vertCount * sizeof(vert_t);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, arrayBufferSize, v, GL_STATIC_DRAW);

	int elemBufferSize = indexCount * sizeof(unsigned int);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemBufferSize, i, GL_STATIC_DRAW);

	BeginAttributeBindingAll();

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	m_VAO = VAO;
	m_drawType = ELEMENT;
	m_count = indexCount;
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
bool Shader::BindUniformMat4(const char* uniformName, const Matrix4x4 val)
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

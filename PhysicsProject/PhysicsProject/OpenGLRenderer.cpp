//================================================================
//              OpenGLRenderer.cpp                                
//================================================================
#include "OpenGLRenderer.hpp"
#include "MathUtilities.hpp"


//================================================================
OpenGLRenderer::OpenGLRenderer()
	: m_windowHandle(NULL)
	, m_deviceContext(NULL)
	, m_renderingContext(NULL)
	, m_displayHeight(NULL)
	, m_displayWidth(NULL)
{
}


//================================================================
void OpenGLRenderer::Startup(HWND windowHandle)
{
	m_windowHandle = windowHandle;
	m_deviceContext = GetDC(windowHandle);
	
	PIXELFORMATDESCRIPTOR pixelFormatDescription;
	memset(&pixelFormatDescription, 0, sizeof(PIXELFORMATDESCRIPTOR));

	pixelFormatDescription.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDescription.cColorBits = 32;
	pixelFormatDescription.nVersion = 1;
	pixelFormatDescription.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

	HWND	myWindowHandle = (HWND)(m_windowHandle);
	HDC		hdc = GetDC(myWindowHandle);

	int		pixelFormat = ChoosePixelFormat(m_deviceContext, &pixelFormatDescription);
	BOOL	didSetFormat = SetPixelFormat(m_deviceContext, pixelFormat, &pixelFormatDescription);

	m_renderingContext = wglCreateContext(m_deviceContext);

	if (didSetFormat)
	{
		wglMakeCurrent(m_deviceContext, m_renderingContext);
		float dimensions[4];
		glGetFloatv(GL_VIEWPORT, dimensions);
		m_displayWidth = dimensions[2];
		m_displayHeight = dimensions[3];

		glViewport(0, 0, m_displayWidth, m_displayHeight);
		
	}
}
void OpenGLRenderer::Shutdown()
{
}


//================================================================
void OpenGLRenderer::PreRender()
{
	glClearColor(.2f, .3f, .3f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
void OpenGLRenderer::PostRender()
{
	::SwapBuffers(m_deviceContext);
}


//================================================================
void OpenGLRenderer::DrawLineLoop(Vector2 v[], RGBA color /*= RGBA::PURPLE*/)
{
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_LINE_LOOP);
	int size = sizeof(v);

	for (int i = 0; i < sizeof(v); i++)
	{
		glVertex2f(v[i].x, v[i].y);
	}
	glEnd();
}
void OpenGLRenderer::DrawLine(Vector2 start, Vector2 end, RGBA color)
{
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_LINES);
		glVertex2f(start.x, start.y);
		glVertex2f(end.x, end.y);
	glEnd();
}
void OpenGLRenderer::DrawLine(Vector3 start, Vector3 end, RGBA color)
{
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_LINES);
	glVertex3f(start.x, start.y, start.z);
	glVertex3f(end.x, end.y, start.z);
	glEnd();
}


//================================================================
void OpenGLRenderer::DrawText(Vector2 position, char* string, RGBA color)
{
	int len, i;

	glColor3f(color.r, color.g, color.b);
	glRasterPos2i(position.x, position.y);
	len = (int)strlen(string);

	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);

}
void OpenGLRenderer::DrawLine(vert_t start, vert_t end, RGBA color /*= RGBA::PURPLE*/)
{
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_LINES);
	glVertex2f(start.m_position.x, start.m_position.y);
	glVertex2f(end.m_position.x, end.m_position.y);
	glEnd();
}
void OpenGLRenderer::DrawLineLoop(vert_t v[], RGBA color)
{
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_LINE_LOOP);
	int size = sizeof(v);

	for (int i = 0; i < sizeof(v); i++)
	{
		glVertex2f(v[i].m_position.x, v[i].m_position.y);
	}
	glEnd();
}



//================================================================
Matrix4x4 OpenGLRenderer::CreateLookAtMatrix(Vector3& r, Vector3& u, Vector3& f, Vector3& p)
{
	return Matrix4x4
	(
		Vector4(r.x, r.y, r.z, 0.0f), Vector4(u.z, u.y, u.z, 0.0f), Vector4(f.z, f.y, f.z, 0.0f), Vector4(-p.x, -p.y, -p.z, 1.0f)
	);
}
Matrix4x4 OpenGLRenderer::CreateProjectionMatrix(float fov, float aspect, float zNear, float zFar)
{
	float f = 1.0f / tan(.5f * ToRadians(fov));
	float s = 1.0f / (zNear - zFar);
	float zDepth = zNear - zFar;
	return Matrix4x4
	(
		Vector4(f / aspect, 0,                       0,  0),
		Vector4(         0, f,                       0,  0),
		Vector4(         0, 0, (zFar + zNear) / zDepth, -1),
		Vector4(         0, 0, (2*zFar*zNear) / zDepth,  0)
	);
}
Matrix4x4 OpenGLRenderer::CreateOrthoMatrix(float screenWidth, float screenHeight, float zFar, float zNear)
{
	return Matrix4x4
	(
		Vector4(2.0f / screenWidth, 0.0f, 0.0f, 0.0f),
		Vector4(0.0f, 2.0f / screenHeight, 0.0f, 0.0f),
		Vector4(0.0f, 0.0f, -2.0f / (zFar - zNear), 0.0f),
		Vector4(-1.0f, -1.0f, 0.0f, 1.0f)
	);
}



#include <stdio.h>
#include <iostream>
#include <Glew\glew.h>
#include <FreeGlut\glut.h>
#include "OpenGLWindow.h"

OpenGLWindow* thisRef;

OpenGLWindow::OpenGLWindow(int argc, char* argv[], std::string windowTitleString)
{
	m_WindowWidth			    = 1920;
	m_WindowHeight				= 1080;
	m_WindowStartingXCoordinate = 0;
	m_WindowStartingYCoordinate = 0;
	m_WindowTitleString			= windowTitleString;
	thisRef						= this;
	m_BresenhamsLine			= new BresenhamsLine(TwoDimentionalCoordinates(50, 50), TwoDimentionalCoordinates(150, 70));
	m_DDALine					= new DDALineAlgo(TwoDimentionalCoordinates(50, 50), TwoDimentionalCoordinates(150, 70));
	UpdateLineCoordinates();
	CreateOpenGLWindow(argc, argv);
}

OpenGLWindow::OpenGLWindow(int windowWidth, int windowHeight,
	int windowStartingXCoordinate, int windowStartingYCoordinate,
	int argc, char* argv[],
	std::string windowTitleString)
{
	m_WindowWidth = windowWidth;
	m_WindowHeight = windowHeight;
	m_WindowStartingXCoordinate = windowStartingXCoordinate;
	m_WindowStartingYCoordinate = windowStartingYCoordinate;
	m_WindowTitleString = windowTitleString;
	thisRef = this;
	m_BresenhamsLine = new BresenhamsLine(TwoDimentionalCoordinates(50, 50), TwoDimentionalCoordinates(150, 70));
	m_DDALine = new DDALineAlgo(TwoDimentionalCoordinates(50, 50), TwoDimentionalCoordinates(150, 70));
	UpdateLineCoordinates();
	CreateOpenGLWindow(argc, argv);
}

OpenGLWindow::~OpenGLWindow()
{
	delete m_BresenhamsLine;
}

void OpenGLWindow::RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for(TwoDimentionalCoordinates coord : thisRef->m_LineCoordinates)
	{
		glVertex2f(coord.x, coord.y);
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void OpenGLWindow::InitializeWindow(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(m_WindowWidth, m_WindowHeight);

	glutInitWindowPosition(m_WindowStartingXCoordinate, m_WindowStartingYCoordinate);

	int win = glutCreateWindow(m_WindowTitleString.c_str());

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0f, 200.0f, 0.0f, 150.0f);
	printf("Window id %d\n", win);
}

bool OpenGLWindow::InitializeGlew()
{
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s' \n", glewGetErrorString(res));
		return false;
	}
	return true;
}

void OpenGLWindow::SetWindowBackgroundColour()
{
	GLclampf Red = 0.0f;
	GLclampf Green = 0.0f;
	GLclampf Blue = 0.0f;
	GLclampf Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);
}


void OpenGLWindow::CreateOpenGLWindow(int argc, char* argv[])
{
	InitializeWindow(argc, argv);

	if (InitializeGlew())
	{
		SetWindowBackgroundColour();
		glutDisplayFunc(RenderSceneCB);
		InitialiseGlutCallBacks();
		glutMainLoop();
	}
}

void OpenGLWindow::InitialiseGlutCallBacks()
{
	glutKeyboardFunc(KeyboardCB);
}

void OpenGLWindow::KeyboardCB(unsigned char key, int mouse_x, int mouse_y)
{
	switch (key)
	{
		case '1':
			thisRef->m_IsUsingDDA = !thisRef->m_IsUsingDDA;
			UpdateLineCoordinates();
			break;
		case 27:
			exit(0);
	}
}

void OpenGLWindow::UpdateLineCoordinates()
{
	if (thisRef->m_IsUsingDDA) { thisRef->m_LineCoordinates = thisRef->m_DDALine->GetCoordinates(); }
	else { thisRef->m_LineCoordinates = thisRef->m_BresenhamsLine->GetCoordinates(); }
}

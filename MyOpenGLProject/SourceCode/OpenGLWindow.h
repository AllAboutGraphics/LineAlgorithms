#pragma once
#include <string>
#include "DDALineAlgo.h"
#include "BresenhamsLine.h"

class OpenGLWindow
{
	private:
		int									   m_WindowWidth;
		int									   m_WindowHeight;
		int									   m_WindowStartingXCoordinate;
		int									   m_WindowStartingYCoordinate;
		std::string							   m_WindowTitleString;
		BresenhamsLine*						   m_BresenhamsLine;
		DDALineAlgo*						   m_DDALine;
		std::vector<TwoDimentionalCoordinates> m_LineCoordinates;
		bool								   m_IsUsingDDA = true;

	public:
		OpenGLWindow(int argc, char* argv[], std::string windowTitleString = "OpenGlWindow");
		OpenGLWindow(int windowWidth, int windowHeight, int windowStartingXCoordinate, int windowStartingYCoordinate, int argc, char* argv[], std::string windowTitleString = "OpenGlWindow");
		~OpenGLWindow();

	private:
		static void RenderSceneCB();
		void InitializeWindow(int argc, char* argv[]);
		bool InitializeGlew();
		void SetWindowBackgroundColour();
		void CreateOpenGLWindow(int argc, char* argv[]);
		void InitialiseGlutCallBacks();
		static void KeyboardCB(unsigned char key, int mouse_x, int mouse_y);
		static void UpdateLineCoordinates();
};
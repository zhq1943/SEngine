#include"sepch.h"
#include "CApplication.h"

#include"Events/ApplicationEvent.h"
#include"CLog.h"

#include<GLFW/glfw3.h>

namespace SEngine {

	CApplication::CApplication()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	CApplication::~CApplication()
	{
	}
	void CApplication::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
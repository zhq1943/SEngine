#include"sepch.h"
#include "CApplication.h"


#include"CLog.h"

#include<GLFW/glfw3.h>
#include<glad/glad.h>

#define BIND_EVENT_FN(x) std::bind(&CApplication::x,this,std::placeholders::_1)

namespace SEngine {

    CApplication* CApplication::s_Instance = nullptr;

	CApplication::CApplication()
	{
		SE_CORE_ASSERT(s_Instance, "Application is exist");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create()); 
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	CApplication::~CApplication()
	{
	}

	void CApplication::PushLayer(CLayer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void CApplication::PopOver(CLayer* layer)
	{
		m_LayerStack.PopOverLayer(layer);
	}

	void CApplication::PushOverLayer(CLayer* layer)
	{
		m_LayerStack.PushOverLay(layer);
		layer->OnAttach();
	}

	void CApplication::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispach<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SE_CORE_TRACE("{0}", event);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(event);
			if (event.Handled())
			{
				break;
			}
		}
	}



	bool CApplication::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void CApplication::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (CLayer* layer:m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();
		}
	}


}
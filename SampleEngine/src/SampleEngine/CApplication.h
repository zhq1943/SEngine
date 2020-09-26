#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Window.h"
#include"Events/ApplicationEvent.h"
#include"CLayerStack.h"
namespace SEngine {


	class  SE_API CApplication
	{
	public:
		CApplication();
		virtual ~CApplication();

		void Run();

		void OnEvent(Event& event);
		void PushLayer(CLayer* layer);
		void PopOver(CLayer* layer);
	private:

		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		CLayerStack m_LayerStack;
	};

	CApplication* CreateApplication();

}
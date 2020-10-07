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
		void PushOverLayer(CLayer* layer);

		inline static CApplication& GetApplication() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window; };
	private:

		bool OnWindowClose(WindowCloseEvent& e);


		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		CLayerStack m_LayerStack;

	private:
		static CApplication* s_Instance;
	};

	CApplication* CreateApplication();

}
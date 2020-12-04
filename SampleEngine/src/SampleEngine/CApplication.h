#pragma once
#include"Core.h"

#include"Window.h"
#include"SampleEngine/Events/Event.h"
#include"SampleEngine/Events/ApplicationEvent.h"

#include"SampleEngine/CLayerStack.h"
#include"SampleEngine/ImGui/ImGuiLayer.h"
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
		ImGuiLayer* m_imGuiLayer;
		bool m_Running = true;
		CLayerStack m_LayerStack;

	private:
		static CApplication* s_Instance;
	};

	CApplication* CreateApplication();

}
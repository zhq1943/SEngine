#pragma once

#include"SampleEngine/Core.h"
#include"SampleEngine/Events/Event.h"
#include"SampleEngine/Events/MouseEvent.h"
#include"SampleEngine/Events/KeyEvent.h"
#include"SampleEngine/Events/ApplicationEvent.h"
#include"SampleEngine/CLayer.h"

namespace SEngine {
	class SE_API ImGuiLayer :public CLayer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
	    void OnDetach();
		void OnUpdate();
		void OnEvent(Event& e);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseButtonScrolleddEvent(MouseScrolledEvent& e);
		bool OnMouseMoveEvent(MouseMoveEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);


	private:
		float m_Time = 0;
	};
}

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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		
		void Begin();
		void End();


	private:
		float m_Time = 0;
	};
}

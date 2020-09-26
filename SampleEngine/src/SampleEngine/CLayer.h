#pragma once

#include"SampleEngine/Core.h"
#include"SampleEngine/Events/Event.h"

namespace SEngine
{
	class SE_API CLayer
	{
	public:
		CLayer(const std::string& name = "Layer");
		virtual ~CLayer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}


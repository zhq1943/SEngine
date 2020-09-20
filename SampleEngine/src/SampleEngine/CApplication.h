#pragma once
#include"Core.h"
#include"Events/Event.h"
#include"Window.h"
namespace SEngine {


	class  SE_API CApplication
	{
	public:
		CApplication();
		virtual ~CApplication();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	CApplication* CreateApplication();

}
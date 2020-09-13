#pragma once
#include"Core.h"

namespace SEngine {


	class  SE_API CApplication
	{
	public:
		CApplication();
		virtual ~CApplication();

		void Run();
	};

	CApplication* CreateApplication();

}
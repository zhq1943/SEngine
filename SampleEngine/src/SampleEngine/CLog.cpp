#include"sepch.h"
#include "CLog.h"

namespace SEngine
{
	std::shared_ptr<spdlog::logger> CLog::s_ClientLogger;
	std::shared_ptr<spdlog::logger> CLog::s_CoreLogger;

	void CLog::Init()
	{
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
		s_CoreLogger = spdlog::stdout_color_mt("SampleEngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
#pragma once

#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
#include"spdlog/fmt/ostr.h"

namespace SEngine {
	class SE_API CLog
	{
	public:
		CLog() {};
		~CLog() {};

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClinetLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//core log macros
#define SE_CORE_TRACE(...)	::SEngine::CLog::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)	::SEngine::CLog::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARM(...)	::SEngine::CLog::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...)	::SEngine::CLog::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...)	::SEngine::CLog::GetCoreLogger()->fatal(__VA_ARGS__)


//client log macros
#define SE_TRACE(...)	::SEngine::CLog::GetClinetLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)	::SEngine::CLog::GetClinetLogger()->info(__VA_ARGS__)
#define SE_WARM(...)	::SEngine::CLog::GetClinetLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...)	::SEngine::CLog::GetClinetLogger()->error(__VA_ARGS__)
#define SE_FATAL(...)	::SEngine::CLog::GetClinetLogger()->fatal(__VA_ARGS__)

#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>
#include <pch.h>

#include "Pine/Core/Core.h"

namespace Pine {


	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger()		{ return s_CoreLogger;   }
		static std::shared_ptr<spdlog::logger>& GetClientLogger()   { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log
#define PN_CORE_ERROR(...)		::Pine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PN_CORE_WARN(...)		::Pine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PN_CORE_INFO(...)		::Pine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PN_CORE_TRACE(...)		::Pine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PN_CORE_FATAL(...)		::Pine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log
#define PN_ERROR(...)		::Pine::Log::GetClientLogger()->error(__VA_ARGS__)
#define PN_WARN(...)		::Pine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PN_INFO(...)		::Pine::Log::GetClientLogger()->info(__VA_ARGS__)
#define PN_TRACE(...)		::Pine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PN_FATAL(...)		::Pine::Log::GetClientLogger()->fatal(__VA_ARGS__)
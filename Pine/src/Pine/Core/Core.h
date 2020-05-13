#pragma once

#ifdef PN_PLATFORM_WINDOWS
	#ifdef  PN_BUILD_DLL
		#define PINE_API _declspec(dllexport)
	#else
		#define PINE_API _declspec(dllimport)
	#endif
#else
	#error Pine only supports Windows!
#endif // PN_PLATFORM_WINDOWS


#ifdef PN_ENABLED_ASSERTS
	#define PN_ASSERT(x, ...) { if(!(x)) { PN_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define PN_CORE_ASSERT(x, ...) { if(!(x)) { PN_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PN_ASSERT(x, ...)
	#define PN_CORE_ASSERT(x, ...)
#endif // PN_ENABLED_ASSERTS


#define BIT(x) (1 << x)
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

#pragma once

#include <pch.h>

#ifdef PN_PLATFORM_WINDOWS

extern Pine::Application* Pine::CreateApplication();

int main(int argc, char** argv)
{
	Pine::Log::Init();
	PN_CORE_ERROR("Initialized Log!");
	int x = 11;
	PN_INFO("Hello {0}", x);

	auto app = Pine::CreateApplication();
	if (app == nullptr) std::cout << "app not be created." << std::endl;
	app->Run();
	delete app;
	//std::cout << "end" << std::endl;
}


#endif // PN_PLATFORM_WINDOWS
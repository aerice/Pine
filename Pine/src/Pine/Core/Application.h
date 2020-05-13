#pragma once
#include <pch.h>

#include "Window.h"
#include "Log.h"

namespace Pine {

	class  Application
	{
	public:
		Application();
		virtual ~Application();


		void OnEvent(Event& e);

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Runing;
	};

	// to be defined in Client
	Application* CreateApplication();
}
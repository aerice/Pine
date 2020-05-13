#pragma once

#include <GLFW/glfw3.h>

#include "Pine/Core/Window.h"
#include "Pine/Core/Log.h"

namespace Pine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props = WindowProps());
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;
		virtual unsigned int GetWidth() const override  { return m_Data.Width; }
		virtual unsigned int GetHeight() const override { return m_Data.Height; }

		// window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		void Init(const WindowProps& props);
		void ShutDown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			
			bool VSync;
			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
	};

}
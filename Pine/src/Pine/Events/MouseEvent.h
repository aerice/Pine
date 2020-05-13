#pragma once

#include "Event.h"

namespace Pine {

	class  MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{

		}

		float GetX() const { return m_MouseX; }
		float GetY() const { return m_MouseY; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};

	class  MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset)
		{
		}

		float GetXOffset() const { return m_XOffset; }
		float GetYOffset() const { return m_YOffset; }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class  MouseButtonEvent : public Event {
	public:

		float GetMouseButton() const { return m_MouseButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)

	protected:
		MouseButtonEvent(int mousebutton)
			: m_MouseButton(mousebutton) {}

		int m_MouseButton;
	};

	class  MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int mousebutton)
		: MouseButtonEvent(mousebutton) {}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class  MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int mousebutton)
			: MouseButtonEvent(mousebutton) {}

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
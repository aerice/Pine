#pragma once

#include "Event.h"


namespace Pine {

	class  KeyEvent : public Event {
	public:
		int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyBoard)
		
	protected:
		int m_KeyCode;

		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}
	};

	class  KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatcount)
			: KeyEvent(keycode), m_RepeatCount(repeatcount)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class  KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{ }

		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};

}
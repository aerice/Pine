#pragma once

#include "Pine/Core/Core.h"
#include <pch.h>

namespace Pine {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFoucs, WindowLostFoucs, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategoty
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyBoard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }


#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class  Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategoty categoty)
		{
			return GetCategoryFlags() & categoty;
		}
	};

	class  EvetnDispatcher
	{
	public:
		EvetnDispatcher(Event& event)
			: m_Event(event)
		{

		}

		template<typename T, typename F>
		bool DisPatch(const F& func)
		{
			if (m_Event.GetEventType == T::GetStaticType()) {
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return false;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator<< (std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}
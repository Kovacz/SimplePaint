#pragma once

#include <variant>

namespace mlg
{

namespace Core
{

class Entity;

enum class EventType
{
	NONE,
	SCROLLED,
	MOUSE_BUTTON_LEFT_PRESSED,
	MOUSE_BUTTON_LEFT_RELEASED,
	KEY_PRESSED,
	KEY_REPEATED,
	KEY_RELEASED,
};

using ScrollOffset   = struct { double x; double y; };
using CursorPosition = struct { double x; double y; };
using KeyboardAction = struct { int key; int scancode; int mods; };

class Event
{
	using EventData = std::variant<ScrollOffset  ,
									CursorPosition,
									KeyboardAction>;
public:
	Event(Entity* receiver) noexcept;
	virtual ~Event() noexcept;

	Entity* receiver() const noexcept;

	template <typename T>
	T const* get() const noexcept
	{
		return std::get_if<T>(&m_data);
	}

	EventType getEventType() const noexcept
	{
		return m_type;
	}

	template <typename T, typename ...Args>
	void set(EventType&& type, Args&& ...args) noexcept
	{
		m_type = type;
		m_data.emplace<T>(T({std::forward<Args>(args) ...}));
	}
private:
	Entity*   m_receiver{nullptr};
	EventType m_type;
	EventData m_data;
};

} // namespace Core

} // namespace mlg

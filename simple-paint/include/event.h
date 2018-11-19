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
    CURSOR_MOVED,
    SCROLLED,
	MOUSE_BUTTON_LEFT_PRESSED,
	MOUSE_BUTTON_LEFT_RELEASED,
    KEY_PRESSED,
    KEY_REPEATED,
    KEY_RELEASED,
};

using CursorPosition = struct { int x; int y; };
using ScrollOffset   = struct { double x; double y; };
using MouseAction    = struct { int button; int mods; };
using KeyboardAction = struct { int key; int scancode; int mods; };

class Event
{
    using EventData = std::variant<CursorPosition,
								   ScrollOffset  ,
								   MouseAction   ,
								   KeyboardAction>;
public:
	Event(Entity* receiver) noexcept;
	virtual ~Event() noexcept;

	Entity* receiver() const noexcept;

    template <typename T>
    T* get() const noexcept;

    template <typename T, typename ...Args>
    void set(EventType&& type, Args&& ...args) noexcept;
private:
	Entity*   m_receiver{nullptr};
    EventType m_type;
    EventData m_data;
};

} // namespace Core

} // namespace mlg

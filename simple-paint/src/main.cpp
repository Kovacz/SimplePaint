#include <iostream>
#include <variant>


enum class EventType
{
    NONE,
    CURSOR_MOVED,
    SCROLLED,
    KEY_PRESSED,
    KEY_REPEATED,
    KEY_RELEASED,
};

class Event
{
public:
    using CursorPosition = struct { int   x; int   y; };
    using ScrollOffset   = struct { float x; float y; };
    using MouseAction    = struct { int button; int mods; };
    using KeyboardAction = struct { int key; int scancode; int mods; };
    using EventData      = std::variant<CursorPosition,
                                        ScrollOffset,
                                        MouseAction,
                                        KeyboardAction>;
public:
    template <typename T>
    T* getAs();

    template <typename T, typename ...Args>
    void set(EventType&& type, Args&& ...args);

private:
    EventType m_type;
    EventData m_data;
};

template <typename T>
T* Event::getAs()
{
    return std::get_if<T>(&m_data);
}

template <typename T, typename ...Args>
void Event::set(EventType&& type, Args&& ...args)
{
    m_type = type;
    m_data.emplace<T>(T({std::forward<Args>(args) ...}));
}


int main()
{
    Event event;
    event.set<Event::KeyboardAction>(EventType::KEY_PRESSED, 159, 217, 1);

    auto action = event.getAs<Event::KeyboardAction>();
    std::cout << action->key << " " << action->mods << " " << action->scancode << std::endl;
}


/*
#include "scene.h"
#include "renderer.h"

using namespace mlg::Graphics;

int main()
{
	auto scene = Scene::make_scene();
	scene.load();

	auto renderer = Renderer::make_renderer();
	renderer(&scene).render();

	return 0;
}
*/

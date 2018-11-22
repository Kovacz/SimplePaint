#pragma once

#include "inputmanager.h"
#include "componentmanager.hpp"
#include "global.h"
#include "event.h"
#include "system.h"
#include "line.h"
#include "graphicsystem.h"

#include <iostream>
#include <vector>

namespace mlg
{

namespace Core
{

class SystemManager final
{
	using SystemPool = std::unordered_map<std::string, System*>;
public:
	SystemManager() noexcept
	{

        this->assign<GraphicSystem>();

		m_inputManager.bind(EventType::MOUSE_BUTTON_LEFT_PRESSED, [&](Event const* event) {
                auto pos = event->get<CursorPosition>();
                if (event->receiver()->getComponent()) {
                    double x = pos->x;
                    double y = pos->y;
                    Global::get_2d_ndc_coords(x, y);
                    event->receiver()->getComponent()->vertices.emplace_back(x);
                    event->receiver()->getComponent()->vertices.emplace_back(y);
                    event->receiver()->getComponent()->vertices.emplace_back(.0);
                }
            });

		m_inputManager.bind(EventType::MOUSE_BUTTON_LEFT_RELEASED, [&](Event const* event) {
                auto pos = event->get<CursorPosition>();
                if (event->receiver()->getComponent()) {
                    double x = pos->x;
                    double y = pos->y;
                    Global::get_2d_ndc_coords(x, y);
                    event->receiver()->getComponent()->vertices.emplace_back(x);
                    event->receiver()->getComponent()->vertices.emplace_back(y);
                    event->receiver()->getComponent()->vertices.emplace_back(.0);

                    event->receiver()->onPaintEvent(*event, *this->get<GraphicSystem>());
                }
            });

		m_inputManager.bind(EventType::KEY_PRESSED, [&](Event const* event) {
                auto keyboard = event->get<KeyboardAction>();
                if (GLFW_KEY_L == keyboard->key) {
                    if (!Global::brush->getComponent()) {
                        auto component = m_componentManager.create<Graphics::Line>();
                        Global::brush->attach(component);
                    }
                    std::cout << "Key 'L' was pressed!" << std::endl;
                }
            });

	}

	~SystemManager() noexcept = default;

    template <typename T>
    void assign() noexcept
    {
        if (m_systems.end() == m_systems.find(typeid(T*).name())) {
            m_systems.emplace(typeid(T*).name(), new T);
            m_systems[typeid(T*).name()]->handler = this;
        }
    }

	template <typename T, typename ...Args>
	void assign(Args&& ...args) noexcept
	{
		if (m_systems.end() == m_systems.find(typeid(T*).name())) {
			m_systems.emplace({typeid(T*).name(), new T(std::forward<Args>(args) ...)});
            m_systems[typeid(T*).name()]->handler = this;
		}
	}

    template <typename T>
    T* get() noexcept
    {
        if (auto f = m_systems.find(typeid(T*).name()); m_systems.end() != f) {
            return dynamic_cast<T*>(f->second);
        }
        return nullptr;
    }

	void processEvent() noexcept
	{
		Event* event = Global::events_pool.front();
        m_inputManager.exec(event);

		Global::events_pool.pop_front();
		delete event;
	}
private:
    InputManager        m_inputManager;
    ComponentManager    m_componentManager;
    SystemPool          m_systems;
};

} // namespace Core

} // namespace mlg

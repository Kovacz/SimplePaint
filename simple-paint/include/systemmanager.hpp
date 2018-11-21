#pragma once

#include "inputmanager.h"
#include "componentmanager.hpp"
#include "global.h"
#include "event.h"
#include "system.h"
#include "line.h"

#include <iostream>
#include <vector>

namespace mlg
{

namespace Core
{

class SystemManager final
{
	using SystemPool = std::unordered_map<std::string, System*>;
    using Vertices   = std::vector<glm::dvec3>;
public:
	SystemManager() noexcept
	{
		m_inputManager.bind(EventType::MOUSE_BUTTON_LEFT_PRESSED, [&](Event const* event) {
			auto pos = event->get<CursorPosition>();
			m_vertices.emplace_back(Global::get_2d_ndc_coords(pos->x, pos->y));
			std::cout << "Mouse button pressed!  x: " << m_vertices.back().x  << " y: "<< m_vertices.back().y << std::endl;
		});

		m_inputManager.bind(EventType::MOUSE_BUTTON_LEFT_RELEASED, [&](Event const* event) {
			auto pos = event->get<CursorPosition>();
			m_vertices.emplace_back(Global::get_2d_ndc_coords(pos->x, pos->y));
			std::cout << "Mouse button released! x: " << m_vertices.back().x  << " y: "<< m_vertices.back().y << std::endl;
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

	template <typename T, typename ...Args>
	void assign(Args&& ...args) noexcept
	{
		if (m_systems.end() == m_systems.find(typeid(T*).name())) {
			m_systems.emplace({typeid(T*).name(), new T(std::forward<Args>(args) ...)});
            m_systems[typeid(T*).name()]->handler = this;
		}
	}

	void processEvent() noexcept
	{
		Event* event = Global::events_pool.front();
        m_inputManager.exec(event);

		Global::events_pool.pop_front();
		delete event;
	}
private:
    Vertices            m_vertices;
    InputManager        m_inputManager;
    ComponentManager    m_componentManager;
    SystemPool          m_systems;
};

} // namespace Core

} // namespace mlg

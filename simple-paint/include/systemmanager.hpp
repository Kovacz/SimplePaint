#pragma once

#include "inputmanager.h"
#include "componentmanager.hpp"
#include "application.h"
#include "system.h"
#include "line.h"
#include "graphicsystem.h"
#include "vector3.hpp"

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
	SystemManager() noexcept;
	~SystemManager() noexcept = default;
	void processEvent() noexcept;
public:
	/*
		* inline instance of template methods
		*/
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
private:
	InputManager        m_inputManager;
	ComponentManager    m_componentManager;
	SystemPool          m_systems;
};

} // namespace Core

} // namespace mlg

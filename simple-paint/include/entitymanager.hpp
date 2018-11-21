#pragma once

#include <cstdint>
#include <unordered_map>
#include <string>

namespace mlg
{

namespace Core
{

class Entity;
class Component;

class EntityManager final
{
    using EntityPool = std::unordered_map<std::string, Entity*>;
public:
	EntityManager() noexcept = default;
	~EntityManager() noexcept = default;

    template <typename T>
    T* create() noexcept
	{
		if (m_entities.end() != exists<T*>()) {
			return nullptr;
		}

		T* new_entity = new T(++m_nextID);
		m_entities.insert({typeid(T*).name(), new_entity});
		return new_entity;
	}

    template <typename T>
    bool remove() noexcept
	{
		if (auto it = exists<T*>(); m_entities.end() != it) {
			m_entities.erase(it);
			return true;
		}
		return false;
	}

    template <typename T>
    auto exists() const noexcept
	{
		if (auto f = m_entities.find(typeid(T*).name()); m_entities.end() != f) {
			return f;
		}
		return m_entities.end();
	}
private:
    size_t    		m_nextID{0};
    EntityPool  	m_entities;
};

} // namespace Core

} // namespace mlg

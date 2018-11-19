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
    using entities_pool = std::unordered_map<std::string, Entity*>;
public:
	EntityManager() noexcept = default;
	~EntityManager() noexcept = default;

    template <typename T>
    T* create() noexcept;

    template <typename T>
    bool remove() noexcept;

    template <typename T>
    auto exists() const noexcept;
private:
    size_t    		m_nextID{0};
    entities_pool  	m_entities;
};

} // namespace Core

} // namespace mlg

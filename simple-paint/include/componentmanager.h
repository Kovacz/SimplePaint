#pragma once

#include <unordered_map>
#include <string>

namespace mlg
{

namespace Core
{

class Entity;
class Component;

class ComponentManager final
{
	using components_pool = std::unordered_map<std::string, Component *>;
public:
	ComponentManager() noexcept = default;
	~ComponentManager() noexcept = default;

	template <typename T>
	Component *createAndSign(Entity *entity) noexcept;

	// get component from our pool
	template <typename T>
	auto exists() const noexcept;
private:
	components_pool m_components;
};

} // namespace Core

} // namespace mlg

#include "componentmanager.h"
#include "entity.h"
#include <algorithm>

namespace mlg
{

namespace Core
{

template <typename T>
auto ComponentManager::exists() const noexcept
{
	if (auto f = m_components.find(typeid(T*).name()); m_components.end() != f) {
		return f;
	}
	return m_components.end();
}

template <typename T>
Component* ComponentManager::createAndSign(Entity* entity) noexcept
{
	if (m_components.end() != exists<T*>()) {
		return nullptr;
	}

	T* new_component = new T;
	m_components.insert({typeid(T*).name(), new_component});
	entity->attach(new_component);
	return new_component;
}

} // namespace Core

} // namespace mlg

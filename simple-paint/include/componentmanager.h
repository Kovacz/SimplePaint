#pragma once

#include <map>
#include <memory>

namespace mlg
{

namespace Core
{

class Component;

class ComponentManager final
{
	using shared_component = std::shared_ptr<Component>;
public:
	ComponentManager() noexcept = default;
	~ComponentManager() noexcept = default;

	bool addComponent(Component* pComponent) noexcept;
	shared_component getComponent(int id) const noexcept;
private:
	int m_newID {0};
	std::map<int, shared_component> m_components;
};

} // namespace Core

} // namespace mlg

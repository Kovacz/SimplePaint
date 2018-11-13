#include "componentmanager.h"
#include "component.h"
#include <algorithm>

namespace mlg
{

namespace Core
{

bool ComponentManager::addComponent(Component* pComponent) noexcept
{
	auto result = std::find_if(m_components.begin(), m_components.end(), [&](auto const& element) {
			return element.second == pComponent;
		});
	if (m_components.end() != result) {
		++m_newID;
		m_components.insert(std::make_pair(m_newID, pComponent));
		return true;
	}
	return false;
}

ComponentManager::shared_component ComponentManager::getComponent(int id) const noexcept
{
	if (auto result = m_components.find(id); m_components.end() != result) {
		return result->second;
	}
	return nullptr;
}

} // namespace Core

} // namespace mlg

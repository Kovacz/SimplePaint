#include "inputmanager.h"

namespace mlg
{

namespace Core
{

void InputManager::bind(EventType&& type, Handler&& action) noexcept
{
    m_bindPool[type].emplace_back(action);
}

void InputManager::exec(Event const* event) noexcept
{
    for (auto const& action : m_bindPool[event->getEventType()]) {
        action(event);
	}
}

} // namespace Core

} // namespace mlg

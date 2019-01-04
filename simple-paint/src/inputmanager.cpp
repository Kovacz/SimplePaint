#include "inputmanager.h"

namespace mlg {

namespace Core {

void InputManager::setHandlerOnEvent(EventType&& type, Handler&& action) noexcept {
    m_bindPool[type].emplace_back(action);
}

void InputManager::free() noexcept {
    assert(m_bindPool.empty());
    m_bindPool.clear();
}

void InputManager::exec(Event const* event) noexcept {
    assert(event);
    for (auto const& action : m_bindPool[event->getEventType()]) {
        action(event);
    }
}

} // namespace Core

} // namespace mlg

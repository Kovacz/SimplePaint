#include "event.h"
#include "entity.h"

namespace mlg
{

namespace Core
{

Event::Event(Entity* receiver) noexcept
    : m_receiver(receiver)
{}

Event::~Event() noexcept
{}

Entity* Event::receiver() const noexcept
{
	return m_receiver;
}

template <typename T>
T* Event::get() const noexcept
{
    return std::get_if<T>(&m_data);
}

template <typename T, typename ...Args>
void Event::set(EventType&& type, Args&& ...args) noexcept
{
    m_type = type;
    m_data.emplace<T>(T({std::forward<Args>(args) ...}));
}

} // namespace Core

} // namespace mlg

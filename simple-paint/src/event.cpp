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

} // namespace Core

} // namespace mlg

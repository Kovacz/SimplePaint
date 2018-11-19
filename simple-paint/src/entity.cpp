#include "entity.h"

namespace mlg
{

namespace Core
{

Entity::Entity(size_t id) noexcept : m_id(id)
{}

Entity::~Entity() noexcept
{}

void Entity::attach(Component* comp) noexcept
{
    assert(comp);
    m_component = comp;
}

size_t Entity::getID() const noexcept
{
    return m_id;
}

Component* Entity::getComponent() const noexcept
{
    return m_component;
}

} // namespace Core

} // namespace mlg

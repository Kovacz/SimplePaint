#include "entitymanager.h"

namespace mlg
{

namespace Core
{

template <typename T>
T* EntityManager::create() noexcept
{
    if (m_entities.end() != exists<T*>()) {
        return nullptr;
    }

    T* new_entity = new T(++m_nextID);
    m_entities.insert({typeid(T*).name(), new_entity});
    return new_entity;
}

template <typename T>
auto EntityManager::exists() const noexcept
{
    if (auto f = m_entities.find(typeid(T*).name()); m_entities.end() != f) {
        return f;
    }
    return m_entities.end();
}

template <typename T>
bool EntityManager::remove() noexcept
{
    if (auto it = exists<T*>(); m_entities.end() != it) {
        m_entities.erase(it);
        return true;
    }
    return false;
}

} // namespace Core

} // namespace mlg

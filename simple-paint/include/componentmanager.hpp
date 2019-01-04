#pragma once

#include "component.h"
#include "entity.h"
#include <string>
#include <unordered_map>

namespace mlg {

namespace Core {

class ComponentManager final {
    using ComponentPool = std::unordered_map<std::string, Component*>;

public:
    ComponentManager() noexcept  = default;
    ~ComponentManager() noexcept = default;

    template <typename T>
    Component* create() noexcept {
        if (m_components.end() != exists<T*>()) {
            return nullptr;
        }

        T* new_component = new T;
        m_components.insert({typeid(T*).name(), new_component});
        return new_component;
    }

    template <typename T>
    auto exists() const noexcept {
        if (auto f = m_components.find(typeid(T*).name()); m_components.end() != f) {
            return f;
        }
        return m_components.end();
    }

private:
    ComponentPool m_components;
};

} // namespace Core

} // namespace mlg

#pragma once

#include <map>
#include <cstdint>

namespace mlg
{

namespace Core
{

class Event;
class Component;
class EntityManager;
class RenderSystem;

class Entity
{
	friend class EntityManager;
protected:
	explicit Entity(size_t handle) noexcept;
	virtual ~Entity() noexcept = 0;
public:
	size_t getID() const noexcept;
    Component* getComponent() const noexcept;

    void attach(Component* comp) noexcept;
    virtual void onPaintEvent(Event const& ev, RenderSystem& rsys) = 0;
private:
	size_t 		m_id;
    Component*  m_component;
};

} // namespace Core

} // namespace mlg

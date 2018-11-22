#pragma once

#include <map>
#include <cstdint>

namespace mlg
{

namespace Core
{

class Component;

class Entity
{
	friend class EntityManager;
protected:
	explicit Entity(size_t handle) noexcept;
	virtual ~Entity() noexcept = 0;
public:
	size_t getID() const noexcept;
	Component* getComponent() const noexcept;

	void attach(class Component* comp) noexcept;
	virtual void onPaintEvent(class Event const& event, class GraphicSystem& gsys) = 0;
protected:
	size_t 		m_id;
	Component*  m_component;
};

} // namespace Core

} // namespace mlg

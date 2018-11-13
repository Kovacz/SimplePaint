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
public:
	explicit Entity(int16_t id);
	virtual ~Entity() noexcept;

	int getID() const noexcept;
private:
	int16_t m_id;
};

} // namespace Core

} // namespace mlg

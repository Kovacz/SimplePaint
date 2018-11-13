#pragma once

namespace mlg
{

namespace Core
{

class Entity;

class Component
{
public:
	Component() noexcept = default;
	virtual  ~Component() noexcept = 0;
	virtual void update() noexcept = 0;
};

} // namespace Core

} // namespace mlg

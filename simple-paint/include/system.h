#pragma once

namespace mlg
{

namespace Core
{

class SystemManager;

class System
{
	friend SystemManager;
protected:
	System() noexcept = default;
	virtual ~System() noexcept = 0;

	SystemManager* handler;
};

} // namespace Core

} // namespace mlg

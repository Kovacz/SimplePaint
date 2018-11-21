#pragma once

namespace mlg
{

namespace Core
{

class SystemManager;

class System
{
	friend class SystemManager;
protected:
	System() noexcept;
    virtual ~System() noexcept = 0;

	SystemManager* handler;
};

} // namespace Core

} // namespace mlg

#pragma once

#include <vector>
#include <unordered_map>
#include <functional>

#include "event.h"

namespace mlg
{

namespace Core
{

class InputManager final
{
    using Handler  = std::function<void(Event const* event)>;
	using BindPool = std::unordered_map<EventType, std::vector<Handler>>;
public:
	InputManager() noexcept = default;
	~InputManager() noexcept = default;

    void bind(EventType&& type, Handler&& action) noexcept;
    void exec(Event const* event) noexcept;
private:
	BindPool m_bindPool;
};

} // namespace Core

} // namespace mlg

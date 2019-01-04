#pragma once

#include <functional>
#include <unordered_map>
#include <vector>

#include "event.h"

namespace mlg {

namespace Core {

class InputManager final {
    using Handler  = std::function<void(Event const* event)>;
    using BindPool = std::unordered_map<EventType, std::vector<Handler>>;

public:
    InputManager() noexcept  = default;
    ~InputManager() noexcept = default;

    void setHandlerOnEvent(EventType&& type, Handler&& action) noexcept;
    void free() noexcept;
    void exec(Event const* event) noexcept;

private:
    BindPool m_bindPool;
};

} // namespace Core

} // namespace mlg

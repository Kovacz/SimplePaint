#pragma once

#include "system.h"
#include <cstdint>
#include <tuple>

namespace mlg {

namespace Core {

class Component;

class GraphicSystem : public System {
    using LocalBuffers = std::tuple<uint32_t, uint32_t, uint32_t>;

public:
    GraphicSystem() noexcept;
    ~GraphicSystem() noexcept override;

    bool draw() noexcept;

    bool update(Component const* component) noexcept;

private:
    uint32_t m_verticesToDraw;

    LocalBuffers m_buffers;
};

} // namespace Core

} // namespace mlg

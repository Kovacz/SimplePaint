#pragma once

#include "entity.h"

namespace mlg {

namespace Core {

class Brush : public Entity {
public:
    explicit Brush(size_t id) noexcept;
    ~Brush() noexcept override;

    void onPaintEvent(class Event const& event, class GraphicSystem& gsys) override;
};

} // namespace Core

} // namespace mlg

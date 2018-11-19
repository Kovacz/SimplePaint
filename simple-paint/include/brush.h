#pragma once

#include "entity.h"

namespace mlg
{

namespace Core
{

class Event;
class GraphicSystem;

class Brush : public Entity
{
public:
	explicit Brush(size_t id) noexcept;
    ~Brush() noexcept override;

    void onPaintEvent(Event const& ev, GraphicSystem& gsys) override;
};

} // namespace Core

} // namespace mlg

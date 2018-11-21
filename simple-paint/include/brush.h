#pragma once

#include "entity.h"

namespace mlg
{

namespace Core
{

class Event;
class RenderSystem;

class Brush : public Entity
{
public:
	explicit Brush(size_t id) noexcept;
    ~Brush() noexcept override;

    void onPaintEvent(Event const& ev, RenderSystem& gsys) override;
};

} // namespace Core

} // namespace mlg

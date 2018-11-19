#include "brush.h"

namespace mlg
{

namespace Core
{

Brush::Brush(size_t id) noexcept : Entity(id)
{}

Brush::~Brush() noexcept
{}

void Brush::onPaintEvent(Event const& ev, GraphicSystem& gsys)
{}

} // namespace Core

} // namespace mlg

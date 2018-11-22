#include "brush.h"
#include "graphicsystem.h"

namespace mlg
{

namespace Core
{

Brush::Brush(size_t id) noexcept : Entity(id)
{}

Brush::~Brush() noexcept
{}

void Brush::onPaintEvent(Event const& event, GraphicSystem& gsys)
{
    gsys.update(m_component);
}

} // namespace Core

} // namespace mlg

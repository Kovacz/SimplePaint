#include "graphicsystem.h"
#include "component.h"

#include <iostream>

namespace mlg
{

namespace Core
{

GraphicSystem::~GraphicSystem() noexcept
{}

void GraphicSystem::draw() noexcept
{
    if (!m_ready) {
        return;
    }
    // draw
    glBindVertexArray(std::get<1>(m_buffers));
    glDrawArrays(GL_LINES, 0, static_cast<int>(m_drawable->vertices.size()));
    glBindVertexArray(0);
}

void GraphicSystem::update(Component const* component) noexcept
{
    m_drawable = component;
    m_buffers = component->multiBuff.getBuffers();
	// update
    glBindBuffer(GL_ARRAY_BUFFER, std::get<0>(m_buffers));
    glBufferData(GL_ARRAY_BUFFER, static_cast<int>(component->vertices.size() * sizeof(Vec3d)), component->vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // set flag ready to draw as true
    m_ready = true;
}

} // namespace Core

} // namespace mlg

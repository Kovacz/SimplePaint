#include "graphicsystem.h"
#include "component.h"

#include <iostream>

namespace mlg {

namespace Core {

GraphicSystem::GraphicSystem() noexcept : m_verticesToDraw(0), m_buffers(0, 0, 0) {}

GraphicSystem::~GraphicSystem() noexcept {}

bool GraphicSystem::draw() noexcept {
    // draw
    if (uint32_t vertexArray = std::get<1>(m_buffers); vertexArray > 0) {
        glBindVertexArray(std::get<1>(m_buffers));
        glDrawArrays(GL_LINES, 0, static_cast<int>(m_verticesToDraw));
        glBindVertexArray(0);
        return true;
    }
    return false;
}

bool GraphicSystem::update(Component const* component) noexcept {
    // set attribs
    m_verticesToDraw = static_cast<uint32_t>(component->vertices.size());
    m_buffers        = component->multiBuff.getBuffers();
    // update
    if (m_verticesToDraw > 0) {
        glBindBuffer(GL_ARRAY_BUFFER, std::get<0>(m_buffers));
        glBufferData(GL_ARRAY_BUFFER,
                     static_cast<int>(component->vertices.size() * sizeof(Vec3d)),
                     component->vertices.data(),
                     GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        return true;
    }
    return false;
}

} // namespace Core

} // namespace mlg

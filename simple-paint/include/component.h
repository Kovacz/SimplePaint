#pragma once

#include "multibuffer.hpp"
#include "vector3.hpp"
#include <vector>

namespace mlg {

namespace Core {

class Component {
    using Vertices = std::vector<Vec3d>;

public:
    Component() noexcept;
    virtual ~Component() noexcept = 0;

    // TODO: rewrite this method
    virtual void update() noexcept = 0;

    Vertices vertices;

    Graphics::MultiBuffer<Graphics::VBO, Graphics::VAO> multiBuff;
};

} // namespace Core

} // namespace mlg

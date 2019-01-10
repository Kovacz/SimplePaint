#include "component.h"

namespace mlg {

using namespace Graphics;

namespace Core {

Component::Component() noexcept {
    // clang-format off
    MultiBuffer<VBO, VAO>::bind(&multiBuff);
      multiBuff.setBufferData(VBO, vertices);
      multiBuff.setAttribPointer<Vec3d>(0, 3, BufferTypes::DOUBLE, 0);
    MultiBuffer<VBO, VAO>::unbind(&multiBuff);
    // clang-format on
}

Component::~Component() noexcept {}

} // namespace Core

} // namespace mlg

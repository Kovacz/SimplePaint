#include "component.h"

namespace mlg
{

using namespace Graphics;

namespace Core
{

Component::Component() noexcept
{
	MultiBuffer<VBO, VAO>::bind(&multiBuff);
        multiBuff.setBufferData(VBO, vertices);
        multiBuff.setAttribPointer<Vec3d>(0, 3, DOUBLE, 0);
    MultiBuffer<VBO, VAO>::unbind(&multiBuff);
}

Component::~Component() noexcept
{}

} // namespace Core

} // namespace mlg

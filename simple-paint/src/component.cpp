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
        glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), reinterpret_cast<void*>(0));
        glEnableVertexAttribArray(0);
        //multiBuff.setAttribPointer(0, 3, 0);
    MultiBuffer<VBO, VAO>::unbind(&multiBuff);
}

Component::~Component() noexcept
{}

} // namespace Core

} // namespace mlg

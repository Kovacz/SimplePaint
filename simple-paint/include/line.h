#pragma once

#include "component.h"
#include "multibuffer.hpp"

namespace mlg
{

namespace Graphics
{

class Line : public Core::Component
{
public:
    Line() = default;
	~Line() noexcept override;
	void update() noexcept override;

    MultiBuffer<VBO, VAO> multiBuff;
};

} // namespace Graphics

} // namespace mlg

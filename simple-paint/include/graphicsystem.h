#pragma once

#include <cstdint>
#include <tuple>
#include "system.h"

namespace mlg
{

namespace Core
{

class Component;

class GraphicSystem : public System
{
	using LocalBuffers = std::tuple<uint32_t, uint32_t, uint32_t>;
public:
	GraphicSystem() noexcept = default;
	~GraphicSystem() noexcept override;

	void draw() noexcept;
	void update(Component const* component) noexcept;
private:
	bool m_ready{false};
	LocalBuffers m_buffers;
	Component const* m_drawable{nullptr};
};

} // namespace Core

} // namespace mlg

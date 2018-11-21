#pragma once

#include "scene.h"
#include "systemmanager.hpp"

namespace mlg
{

class Engine final
{
	using Scene = Graphics::Scene;
public:
	bool load() noexcept;
	void run(Scene const& scene) noexcept;
private:
	Core::SystemManager m_systemManager;
	Graphics::ShaderBuilder m_shaderProgram;
};

} // namespace mlg

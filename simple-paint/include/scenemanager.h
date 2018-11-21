#pragma once

#include "scene.h"
#include <list>

namespace mlg
{

class SceneManager
{
	using Scene = Graphics::Scene;
public:
	Scene const& create();
private:
	std::list<Scene> m_scenes;
};

} // namespace mlg

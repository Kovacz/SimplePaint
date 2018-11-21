#include "scenemanager.h"

namespace mlg
{

SceneManager::Scene const& SceneManager::create()
{
	m_scenes.push_back(Scene());
	return m_scenes.back();
}

} // namespace mlg

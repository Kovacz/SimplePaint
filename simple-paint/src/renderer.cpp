#include "renderer.h"
#include "scene.h"
#define COLOR_WHITE 1.f, 1.f, 1.f

namespace mlg
{

namespace Graphics
{

Renderer::~Renderer() noexcept
{
	assert(m_pScene);
	m_pScene = nullptr;
}

Renderer &Renderer::operator()(Scene *scene) noexcept
{
	assert(scene);
	m_pScene = scene;
	return *this;
}

void Renderer::add(Primitive *primitive) const noexcept
{
	m_targets.push_back(primitive);
}

void Renderer::render() const noexcept
{
	while (*m_pScene) {
		m_pScene->setBgColor(COLOR_WHITE, 1.f);
		m_pScene->onDraw();
		/*  expects:
         *  for (auto it = m_targets.rbegin(); it != m_targets.rend(); ++it) {
         *      *it->onDraw();
         *  }
         */
		m_pScene->display();
	}
}

Renderer Renderer::make_renderer()
{
	return Renderer();
}

} // namespace Graphics

} // namespace mlg

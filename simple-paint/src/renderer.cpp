#include "renderer.h"
#include "scene.h"
#define COLOR_WHITE 1.f, 1.f, 1.f

namespace mlg
{

namespace Graphics
{

void Renderer::add(Scene *scene) const noexcept
{
	m_targets.push_back(scene);
}

void Renderer::render() const noexcept
{
	while (m_targets.back()) {
		m_targets.back()->setBgColor(COLOR_WHITE, 1.f);
		m_targets.back()->onDraw();

		m_targets.back()->display();
	}
}

Renderer Renderer::make_renderer()
{
	return Renderer();
}

} // namespace Graphics

} // namespace mlg

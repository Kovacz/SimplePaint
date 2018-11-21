#pragma once

#include <vector>

namespace mlg
{

namespace Graphics
{

class Scene;
class Primitive;

class Renderer final
{
public:
	Renderer() noexcept = default;
	~Renderer() noexcept;
	// delete unused functionality
	Renderer(Renderer&&) = delete;
	Renderer(Renderer const&) = delete;
	Renderer& operator=(Renderer&&) = delete;
	Renderer& operator=(Renderer const&) = delete;
	// for first time
	Renderer& operator()(Scene* scene) noexcept;
	void add(Primitive* primitive) const noexcept;
	void render() const noexcept;
public:
	// smoothly creating
	static Renderer make_renderer();
private:
	// Scene* m_pScene{nullptr};
	// TODO: think and then think one more time
	mutable std::vector<Primitive*> m_targets;
};

} // namespace Graphics

} // namespace mlg

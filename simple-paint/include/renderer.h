#pragma once

#include <vector>

namespace mlg
{

namespace Graphics
{

class Scene;

class Renderer final
{
public:
	Renderer() noexcept = default;
	~Renderer() noexcept = default;
    // delete unused functionality
    Renderer(Renderer&&) = delete;
    Renderer(Renderer const&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    Renderer& operator=(Renderer const&) = delete;
    //
	void add(Scene* scene) const noexcept;
	void render() const noexcept;
public:
    // smoothly creating
	static Renderer make_renderer();
private:
    // TODO: think and then think one more time
	mutable std::vector<Scene*> m_targets;
};

} // namespace Graphics

} // namespace mlg

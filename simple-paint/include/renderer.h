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
	void add(Scene* scene) const noexcept;
	void render() const noexcept;
public:
	//
	static Renderer make_renderer();
private:
	mutable std::vector<Scene*> m_targets;
};

} // namespace Graphics

} // namespace mlg
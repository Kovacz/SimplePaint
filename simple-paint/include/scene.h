#pragma once

#include "window.h"
#include "camera.h"
#include "shaderbuilder.h"

namespace mlg
{

namespace Graphics
{

class Scene
{
	friend class SceneManager;
public:
	Scene();
	~Scene() noexcept;

	GLFWwindow* operator()() const noexcept;
	explicit operator bool() const noexcept;

	void onDraw();
	void onUpdate();
	void display() const noexcept;
	void setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept;
private:
	Window	m_window;
	Camera 	m_camera;
};

} // namespace Graphics

} // namespace mlg

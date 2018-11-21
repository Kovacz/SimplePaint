#pragma once

#include "window.h"
#include "camera.h"
#include "shaderbuilder.h"

namespace mlg
{

class Engine;

namespace Graphics
{

class SceneManager;

class Scene
{
    friend Engine;
    friend SceneManager;
public:
	Scene();
	~Scene() noexcept;
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

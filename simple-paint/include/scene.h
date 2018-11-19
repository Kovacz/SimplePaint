#pragma once

#include "window.h"
#include "camera.h"
#include "texture.h"
#include "shaderbuilder.h"
#include "brush.h"
#include "entitymanager.h"

#include <deque>

namespace mlg
{

namespace Graphics
{

class Event;

class Scene final
{
public:
	Scene();
	~Scene() noexcept;
	explicit operator bool() const noexcept;
	// delete unused functionality
	Scene(Scene&&) = delete;
	Scene(Scene const&) = delete;
	Scene& operator=(Scene&&) = delete;
	Scene& operator=(Scene const&) = delete;
	// TODO: drawing and updating here?
	void onDraw();
	void onUpdate();
	// TODO: make sure about all noexcept here
	bool load() noexcept;
	void display() const noexcept;
	void setBgColor(float const& r, float const& g, float const& b, float const& a) const noexcept;
private:
	// "self use" only
	void gladInit() const;
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
	static void scrollCallback(GLFWwindow* window, double x, double y);
private:

    static Core::Brush* brush;
    Core::EntityManager m_emanager;

    static std::deque<Event*> events_pool;

	System::Window*			m_pWindow {nullptr};
	Graphics::Texture*		m_pTexture{nullptr};

	Graphics::Camera 		m_camera;
	Graphics::ShaderBuilder m_shaderProgram;
};

} // namespace Graphics

} // namespace mlg

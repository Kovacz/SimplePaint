#include "scene.h"
#include "global.h"
#include <glad/glad.h>
#include <iostream>

namespace mlg
{

namespace Graphics
{

Scene::Scene()
	: m_window(800, 600, "Paint")
{
	try {
		m_window.create();
		m_window.setFramebufferSizeCallback();
		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
			throw "Failed to load glad!";
		}
	}
	catch (char const* error) {
		std::cerr << error << std::endl;
	}
}

Scene::~Scene() noexcept
{
}

Scene::operator bool() const noexcept
{
	return m_window.isOpen();
}

void Scene::onDraw()
{
	// Graphics::Texture::bind(m_pTexture);

	// shaderProg.setMat4("model", camera.getModelMat());
	// myWindow.draw(texture);
	// myWindow.display();
}

void Scene::onUpdate()
{
}

void Scene::display() const noexcept
{
	glfwSwapBuffers(m_window.getHandle());
	glfwWaitEvents();
}

void Scene::setBgColor(float const &r, float const &g, float const &b, float const &a) const noexcept
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace Graphics

} // namespace mlg

#include "window.h"
#include <glad/glad.h>
#include <iostream>

inline void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
	glViewport(0, 0, width, height);
}

namespace mlg
{

namespace System
{

Window::Window(int width, int height, char const *name)
	: m_width(width), m_height(height), m_name(name)
{
	if (GLFW_FALSE == glfwInit()) {
		throw "RenderWindow::RenderWindow - glfwInit() function fails\n";
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
#endif
}

Window::~Window() noexcept
{
}

void Window::close() const noexcept
{
	glfwTerminate();
}

void Window::create()
{
	if (!m_width || !m_height || !m_name) {
		glfwTerminate();
		throw "ERROR::WINDOW::CREATE 'invalid input parameters'\n";
	}

	m_handle = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
	if (nullptr == m_handle) {
		glfwTerminate();
		throw "ERROR::WINDOW::CREATE 'failed to create GLFW window'\n";
	}
	glfwMakeContextCurrent(m_handle);
}

bool Window::isOpen() const noexcept
{
	return !glfwWindowShouldClose(m_handle);
}

void Window::setFramebufferSizeCallback() const noexcept
{
	glfwSetFramebufferSizeCallback(m_handle, framebuffer_size_callback);
}

Window::handle Window::getHandle() const noexcept
{
	return m_handle;
}

Window::info Window::getInfo() const noexcept
{
	return std::make_tuple(m_width, m_height, m_name);
}

} // namespace System

} // namespace mlg

#include "window.h"
#include <iostream>

namespace mlg
{

namespace System
{

Window::Window(unsigned width, unsigned height, char const* name)
        : m_width(width)
        , m_height(height)
        , m_name(name)
{
    if (GLFW_FALSE == glfwInit()) {
        throw "RenderWindow::RenderWindow - glfwInit() function fails";
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
        throw "RenderWindow::create - invalid input parameters";
    }

    m_handle = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
	if (nullptr == m_handle) {
		glfwTerminate();
        throw "RenderWindow::create - failed to create GLFW window";
	}
    glfwMakeContextCurrent(m_handle);
}

bool Window::isOpen() const noexcept
{
    return !glfwWindowShouldClose(m_handle);
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

#include "../include/renderwindow.h"
#include <iostream>
namespace mlg
{

RenderWindow::RenderWindow(unsigned width, unsigned height, char const* name)
        : m_width(width)
        , m_height(height)
        , m_name(name)
{
    if (OpenGL::FALSE != OpenGL::init()) {
        std::cerr << "RenderWindow::RenderWindow - glfwInit() function fails" << std::endl;
    }
    OpenGL::setCoreProfile(3, 3, OpenGL::CORE);
}

RenderWindow::~RenderWindow() noexcept
{

}

GLFWwindow* RenderWindow::getHandle() const noexcept
{
    return m_windowHandle;
}

void RenderWindow::create() noexcept
{
    if (!m_width || !m_height || !m_name) {
        return;
    }

    m_windowHandle = OpenGL::createWindow(m_width, m_height, m_name);
	if (nullptr != m_windowHandle)
	{
		std::cerr << "RenderWindow::create - failed to create GLFW window" << std::endl;
		glfwTerminate();
        return;
	}
    OpenGL::makeContextCurrent(m_windowHandle);
    OpenGL::setFramebufferSizeCallback(m_windowHandle, nullptr);
    // glad load
}

RenderWindow::Params RenderWindow::getWindowParams() const noexcept
{
    return std::make_tuple(m_width, m_height, m_name);
}

} // namespace mlg

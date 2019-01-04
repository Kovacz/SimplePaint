#include "window.h"
#include <glad/glad.h>
#include <iostream>

inline void framebuffer_size_callback(GLFWwindow*, int width, int height) { glViewport(0, 0, width, height); }

namespace mlg {

namespace Graphics {

Window::Window(int width, int height, char const* name) : m_width(width), m_height(height), m_name(name) {}

Window::~Window() noexcept {}

void Window::close() const noexcept { glfwTerminate(); }

void Window::create() {
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

bool Window::isOpen() const noexcept { return !glfwWindowShouldClose(m_handle); }

void Window::setFramebufferSizeCallback() const {
    (void)glfwSetFramebufferSizeCallback(m_handle, framebuffer_size_callback);
}

Window::handle Window::getHandle() const noexcept { return m_handle; }

Window::info Window::getInfo() const noexcept { return std::make_tuple(m_width, m_height, m_name); }

} // namespace Graphics

} // namespace mlg

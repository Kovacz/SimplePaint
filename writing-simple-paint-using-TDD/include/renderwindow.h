#pragma once

#include <GLFW/glfw3.h>

namespace mlg 
{

class RenderWindow
{
public:
    RenderWindow(int width_, int height_, char const* name);
    GLFWwindow* getHandle() const noexcept;
private:
    unsigned m_width;
    unsigned m_height;
    GLFWwindow* m_glfwWindow;
};

} // namespace mlg
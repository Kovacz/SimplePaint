#include "opengl.h"

namespace mlg
{

OpenGL::~OpenGL() noexcept
{}

int OpenGL::init()
{
    if (GLFW_FALSE != glfwInit()) {
        return OpenGL::TRUE;
    }
    return OpenGL::FALSE;
}

void OpenGL::setCoreProfile(int major, int minor, int core)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, core);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, OpenGL::TRUE);
#endif
}

void OpenGL::makeContextCurrent(GLFWwindow* window)
{
    glfwMakeContextCurrent(window);
}

OpenGL::WindowHandle OpenGL::createWindow(int width, int height, char const* name)
{
    return glfwCreateWindow(width, height, name, nullptr, nullptr);
}

OpenGL::Callback OpenGL::setFramebufferSizeCallback(GLFWwindow* window, Callback cbfun)
{
    glfwSetFramebufferSizeCallback(window, cbfun);
}

} // namespace mlg
#pragma once 

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <type_traits>
#include <tuple>

namespace mlg
{

class OpenGL final
{
    using Callback  = std::add_pointer<void(GLFWwindow*, int, int)>::type;
public:
    using WindowHandle = GLFWwindow*;

    enum {  CORE    = 0x00032001,
            COMPAT  = 0x00032002,
            FALSE   = 0x0,
            TRUE    = 0x1         };
private:
    OpenGL() = delete;
    virtual ~OpenGL() noexcept = 0;
public:
    static int init();
    static void setCoreProfile(int major, int minor, int core);

    static void makeContextCurrent(OpenGL::WindowHandle window);

    static OpenGL::WindowHandle createWindow(int width, int height, char const* name);
    //static GLFWwindow* createWindow(int width, int height, char const* name);
    static Callback setFramebufferSizeCallback(GLFWwindow* window, Callback cbfun);
};

} // namespace mlg
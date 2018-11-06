#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <tuple>

namespace mlg 
{

namespace System
{

class Window
{
    using info   = std::tuple<unsigned, unsigned, char const*>; 
    using handle = GLFWwindow*;
public:
    Window(unsigned width, unsigned height, char const* name);
    ~Window() noexcept;
   
    void close() const noexcept;    
    void create();
    bool isOpen() const noexcept;
    
    info getInfo() const noexcept;
    handle getHandle() const noexcept;
private:
    unsigned m_width     {0u};
    unsigned m_height    {0u};
    char const* m_name   {nullptr};
    GLFWwindow* m_handle {nullptr};
};

} // namespace system

} // namespace mlg
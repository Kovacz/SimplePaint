#pragma once

#include "opengl.h"

namespace mlg 
{

class RenderWindow
{
    using Params = std::tuple<unsigned, unsigned, char const*>; 
public:
    RenderWindow(unsigned width, unsigned height, char const* name);
    ~RenderWindow() noexcept;

    void display();
    void draw();
    
    void close();
    void create() noexcept;
    
    bool isOpen();

    GLFWwindow* getHandle()  const noexcept;
    Params getWindowParams() const noexcept;
private:
    unsigned m_width            {0u};
    unsigned m_height           {0u};
    char const* m_name          {nullptr};
    GLFWwindow* m_windowHandle  {nullptr};
};

} // namespace mlg
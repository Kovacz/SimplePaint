#include "../include/renderwindow.h"

namespace mlg
{

RenderWindow::RenderWindow(int width_, int height_, char const* name)
{

}

GLFWwindow* RenderWindow::getHandle() const noexcept
{
    return (GLFWwindow*)1;
}

} // namespace mlg

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
namespace mlg {

class Vertex;

class RenderWindow
{
public:
    RenderWindow(int width, int height, const char* wndName, GLFWmonitor *monitor = nullptr, GLFWwindow *share = nullptr);
   ~RenderWindow();

    void draw();
    void draw(const Vertex* vertices);
    void create();
    bool isOpen() const;
    void close() const;
    void display() const;
    void setBgColor(float r,float g,float b,float a) const;
protected:
    int gladLoad();
private:
    int             m_width;
    int             m_height;
    const char*     m_cWindowName;
    GLFWmonitor*    m_monitor;
    GLFWwindow*     m_share;
    GLFWwindow*     m_window;
};

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

} // namespace mlg

#endif // GRAPHICS_H

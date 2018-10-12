#include "../include/graphics.h"
#include "../include/vertex.h"
#include "../include/keyhandler.h"
#include "../include/vertexbuffer.h"
using mlg::Vertex;
using mlg::RenderWindow;
using mlg::VertexBuffer;
using mlg::KeyHandler;

RenderWindow::RenderWindow(int width
        , int          height
        , const char*  wndName
        , GLFWmonitor* monitor /* = nullptr */
        , GLFWwindow*  share   /* = nullptr */
        )
        : m_width(width)
        , m_height(height)
        , m_cWindowName(wndName)
        , m_monitor(monitor)
        , m_share(share)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

RenderWindow::~RenderWindow()
{}

void RenderWindow::draw()
{
    glfwSetMouseButtonCallback(this->m_window, KeyHandler::startMouseTrack);
}

void RenderWindow::draw(const Vertex* vertices)
{
    VertexBuffer vbx;
    vbx.create(vertices, 3);

    VertexBuffer::bind(&vbx);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    VertexBuffer::unbind(&vbx);
}

void RenderWindow::create()
{
    this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_cWindowName, this->m_monitor, this->m_share);
    if (this->m_window == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(this->m_window);
    glfwSetFramebufferSizeCallback(this->m_window, mlg::framebuffer_size_callback);
    this->gladLoad();
}

int RenderWindow::gladLoad()
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            return -1;
        }
    return 0;
}

bool RenderWindow::isOpen() const
{
    return !glfwWindowShouldClose(this->m_window);
}

void RenderWindow::close() const
{
    glfwTerminate();
}

void RenderWindow::setBgColor(float r,float g,float b,float a) const
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderWindow::display() const
{
    glfwSwapBuffers(this->m_window);
    glfwPollEvents();
}

void mlg::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

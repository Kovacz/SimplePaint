#include "../include/renderwindow.h"
#include "../include/vertex.h"
#include "../include/keyhandler.h"
#include "../include/texture.h"
#include "../include/globaldefines.h"
#include <iostream>

namespace mlg
{

GlobalDefines& singleGlobalDefines = GlobalDefines::getInstance();

RenderWindow::RenderWindow(int width, int height, const char* windowName)
		: m_width(width)
		, m_height(height)
		, m_cWindowName(windowName)
        , m_brush(nullptr)
        , m_lineShape(nullptr)
        , m_circleShape(nullptr)
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
{
	if (this->m_brush)
		delete this->m_brush;
	if (this->m_lineShape)
		delete this->m_lineShape;
	if (this->m_circleShape)
		delete this->m_circleShape;
}

void RenderWindow::draw()
{
    if (singleGlobalDefines.lines_mode)
	{
        if (this->m_lineShape == nullptr)
			this->m_lineShape = new LineShape;

        if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::LINES_MODE)
            if (singleGlobalDefines.getDrawFlagState() == true)
            {
                this->m_lineShape->updateBuffers();
				singleGlobalDefines.setDrawFlag(false);
            }
		this->m_lineShape->render();
	}
    if (singleGlobalDefines.circle_mode)
	{
        if (this->m_circleShape == nullptr)
			this->m_circleShape = new CircleShape;
		
        if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::CIRCLE_MODE)
        {
            this->m_circleShape->calculate();
            if (singleGlobalDefines.getDrawFlagState() == true)
            {
                this->m_circleShape->updateBuffers();
				singleGlobalDefines.setDrawFlag(false);
            }
        }
        this->m_circleShape->render();
	}
    if (singleGlobalDefines.brush_mode)
	{
        if (this->m_brush == nullptr)
			this->m_brush = new Brush;

        if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::BRUSH_MODE)
        {
            this->m_brush->pullVertices(this->m_window);
            if (singleGlobalDefines.getDrawFlagState() == true)
            {
                this->m_brush->updateBuffers();
				singleGlobalDefines.setDrawFlag(false);
            }
        }
		this->m_brush->startPaint();
	}
}
void RenderWindow::draw(Texture& texture)
{
   if (singleGlobalDefines.texture_mode)
   {
       texture.render();
   }
   if (singleGlobalDefines.lines_mode)
   {
       if (this->m_lineShape == nullptr)
           this->m_lineShape = new LineShape;

       if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::LINES_MODE)
           if (singleGlobalDefines.getDrawFlagState() == true)
           {
               this->m_lineShape->updateBuffers();
			   singleGlobalDefines.setDrawFlag(false);
           }
       this->m_lineShape->render();
   }
   if (singleGlobalDefines.circle_mode)
   {
       if (this->m_circleShape == nullptr)
           this->m_circleShape = new CircleShape;

       if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::CIRCLE_MODE)
       {
           this->m_circleShape->calculate();
           if (singleGlobalDefines.getDrawFlagState() == true)
           {
               this->m_circleShape->updateBuffers();
			   singleGlobalDefines.setDrawFlag(false);
           }
       }
       this->m_circleShape->render();
   }
   if (singleGlobalDefines.brush_mode)
   {
       if (this->m_brush == nullptr)
           this->m_brush = new Brush;

       if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::BRUSH_MODE)
       {
           this->m_brush->pullVertices(this->m_window);
           if (singleGlobalDefines.getDrawFlagState() == true)
           {
               this->m_brush->updateBuffers();
			   singleGlobalDefines.setDrawFlag(false);
           }
       }
       this->m_brush->startPaint();
   }
   if (singleGlobalDefines.getModeState() == GlobalDefines::DrawMods::SAVE_MODE)
   {
	   texture.save();
	   singleGlobalDefines.setMode(GlobalDefines::DrawMods::UNDEFINED);
   }
}

void RenderWindow::draw(const Vertex* vertices)
{
	// TODO:
}

void RenderWindow::create()
{
	this->m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_cWindowName, nullptr, nullptr);
	if (this->m_window == nullptr)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(this->m_window);
	glfwSwapInterval(1);
    glfwSetFramebufferSizeCallback(this->m_window, mlg::framebuffer_size_callback);
	this->gladLoad();
}
GLFWwindow* RenderWindow::getGLFWwindow() const noexcept
{
	if (this->m_window)
		return this->m_window;
	return nullptr;
}
bool RenderWindow::gladLoad() const
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return false;
	}
	return true;
}
bool RenderWindow::isOpen() const
{
	return !glfwWindowShouldClose(this->m_window);
}
void RenderWindow::close() const
{
	glfwTerminate();
}
void RenderWindow::setBgColor(const float& r, const float& g, const float& b, const float& a) const noexcept
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}
void RenderWindow::display() const
{
    glfwSwapBuffers(this->m_window);
	glfwPollEvents();
}

}

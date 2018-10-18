#include "glad/glad.h"
#include "../include/renderwindow.h"
#include <iostream>
#include "../include/vertex.h"
#include "../include/keyhandler.h"
#include "../include/texture.h"
#include "../include/camera2d.h"

namespace mlg
{

bool		g_drawFlag = false;
float		g_X1 = 0.f;
float		g_Y1 = 0.f;
float		g_X2 = 0.f;
float		g_Y2 = 0.f;
Vertex3     g_linesVert;
Vertex3     g_stripVert;
Vertex3     g_brushVert;
Vertex3     g_circleVert;
DrawMode&   singleDrawMode = DrawMode::getInstance();
char        g_bgMode        = -1;
char        g_linesMode     = -1;
char        g_stripMode     = -1;
char        g_circleMode    = -1;
char        g_brushMode   = -1;

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
    , m_buff(0)
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
//	if (singleDrawMode.getDrawFlagState())
//	{
//		this->m_vbo.update(g_vertices);
//		singleDrawMode.setDrawFlag(false);
//	}
//	if (singleDrawMode.getModeState() == DrawMode::LINES_MODE)
//		glDrawArrays(GL_LINES, 0, g_vertices.size());
//	else if (singleDrawMode.getModeState() == DrawMode::LINES_STRIP_MODE)
//		glDrawArrays(GL_LINE_STRIP, 0, g_vertices.size());
//	else if (singleDrawMode.getModeState() == DrawMode::BRUSH_MODE)
//	{
//		if (KeyHandler::mouseClicked)
//		{
//			singleDrawMode.setDrawFlag(true);
//			double xpos = 0.f, ypos = 0.f;
//			glfwGetCursorPos(this->m_window, &xpos, &ypos);
//			g_X1 = static_cast<float>( (xpos - (this->m_width  / 2)) / (this->m_width  / 2));
//			g_Y1 = static_cast<float>(-(ypos - (this->m_height / 2)) / (this->m_height / 2));
//			g_vertices.push_back(Vector3f(g_X1, g_Y1, 0.f));
//		}
//		else
//		{
//			g_vertices.clear();
//		}
//		glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, g_vertices.size());
//	}
}

void RenderWindow::draw(const Texture& texture, CircleShape& circle) const
{
	if (singleDrawMode.getDrawFlagState())
	{
        if (singleDrawMode.getModeState() == DrawMode::LINES_MODE)
        {
            this->m_buff[0].update(g_linesVert);
        }
        if (singleDrawMode.getModeState() == DrawMode::BRUSH_MODE)
        {
            this->m_buff[1].update(g_brushVert);
        }
        if (singleDrawMode.getModeState() == DrawMode::LINES_STRIP_MODE)
        {
            this->m_buff[2].update(g_stripVert);
        }
        if (singleDrawMode.getModeState() == DrawMode::CIRCLE_MODE)
        {
            this->m_buff[3].update(g_circleVert);
        }
        singleDrawMode.setDrawFlag(false);
	}

    if (singleDrawMode.getModeState() == DrawMode::LOAD_BG_MODE || g_bgMode == 1)
    {
        glBindVertexArray(textureVAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
    if (singleDrawMode.getModeState() == DrawMode::LINES_MODE || g_linesMode == 1)
	{
        glBindVertexArray(this->m_buff[0].getVAOHandle());
        glDrawArrays(GL_LINES, 0, g_linesVert.size());
        glBindVertexArray(0);
	}
    if (singleDrawMode.getModeState() == DrawMode::LINES_STRIP_MODE || g_stripMode == 1)
    {
        glBindVertexArray(this->m_buff[2].getVAOHandle());
        glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, g_stripVert.size());
        glBindVertexArray(0);
    }
    if (singleDrawMode.getModeState() == DrawMode::BRUSH_MODE || g_brushMode == 1)
    {
        if (KeyHandler::mouseClicked && singleDrawMode.getModeState() == DrawMode::BRUSH_MODE)
        {
            singleDrawMode.setDrawFlag(true);
            double xpos = 0.f, ypos = 0.f;
            glfwGetCursorPos(this->m_window, &xpos, &ypos);
            g_X1 = static_cast<float>( (xpos - (this->m_width  / 2)) / (this->m_width  / 2));
            g_Y1 = static_cast<float>(-(ypos - (this->m_height / 2)) / (this->m_height / 2));
            g_brushVert.push_back(Vector3f(g_X1, g_Y1, 0.f));
        }

//        else
//        {
//            g_brushVert.clear();
//        }
        glBindVertexArray(this->m_buff[1].getVAOHandle());
        glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, g_brushVert.size());
        glBindVertexArray(0);

        if (KeyHandler::mouseRelease)
        {
            //g_brushVert.clear();
        }

    }
    if (singleDrawMode.getModeState() == DrawMode::CIRCLE_MODE || g_circleMode == 1)
    {
        circle.redraw();
    }
}

void RenderWindow::draw(const Vertex* vertices) const
{
	// 	if (this->m_drawFlag)
	// 		this->m_vbo.update(vertices, 2);
	// 	glDrawArrays(GL_LINES, 0, 2);
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
	glfwSwapInterval(1);
	glfwSetFramebufferSizeCallback(this->m_window, mlg::framebuffer_size_callback);
	this->gladLoad();

    for (unsigned i = 0; i < 4; ++i)
    {
        VertexBuffer buffer;
        if (i == 0)
            buffer.init(g_linesVert);
        else if (i == 1)
            buffer.init(g_brushVert);
        else if (i == 2)
            buffer.init(g_stripVert);
        else if (i == 3)
            buffer.init(g_circleVert);
        this->m_buff.push_back(buffer);
    }

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

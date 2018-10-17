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
Vertex3		g_vertices;
std::size_t index = 0;
mlg::DrawMode& singleDrawMode = mlg::DrawMode::getInstance();

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
	if (singleDrawMode.getDrawFlagState())
	{
		this->m_vbo.update(g_vertices);
		singleDrawMode.setDrawFlag(false);
	}
	if (singleDrawMode.getModeState() == DrawMode::LINES_MODE)
		glDrawArrays(GL_LINES, 0, g_vertices.size());
	else if (singleDrawMode.getModeState() == DrawMode::LINES_STRIP_MODE)
		glDrawArrays(GL_LINE_STRIP, 0, g_vertices.size());
	else if (singleDrawMode.getModeState() == DrawMode::BRUSH_MODE)
	{
		if (KeyHandler::mouseClicked)
		{
			singleDrawMode.setDrawFlag(true);
			double xpos = 0.f, ypos = 0.f;
			glfwGetCursorPos(this->m_window, &xpos, &ypos);
			g_X1 = static_cast<float>( (xpos - (this->m_width  / 2)) / (this->m_width  / 2));
			g_Y1 = static_cast<float>(-(ypos - (this->m_height / 2)) / (this->m_height / 2));
			g_vertices.push_back(Vector3f(g_X1, g_Y1, 0.f));
		}
		else
		{
			g_vertices.clear();
		}
		glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, g_vertices.size());
	}
}

void RenderWindow::draw(const Texture& texture, CircleShape& circle) const
{
	if (singleDrawMode.getDrawFlagState())
	{
		this->m_vbo.update(g_vertices);
		singleDrawMode.setDrawFlag(false);
	}

    if (singleDrawMode.getModeState() == DrawMode::LOAD_BG_MODE)
    {
        glBindVertexArray(textureVAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
    else if (singleDrawMode.getModeState() == DrawMode::LINES_MODE)
	{
        glBindVertexArray(drawableVAO);
		glDrawArrays(GL_LINES, 0, g_vertices.size());
        glBindVertexArray(0);
	}
	else if (singleDrawMode.getModeState() == DrawMode::LINES_STRIP_MODE)
	{
        glBindVertexArray(drawableVAO);
        glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, g_vertices.size());
        glBindVertexArray(0);
	}
	else if (singleDrawMode.getModeState() == DrawMode::BRUSH_MODE)
	{
		if (KeyHandler::mouseClicked)
		{
			singleDrawMode.setDrawFlag(true);
			double xpos = 0.f, ypos = 0.f;
			glfwGetCursorPos(this->m_window, &xpos, &ypos);
            g_X1 = static_cast<float>( (xpos - (this->m_width  / 2)) / (this->m_width  / 2));
            g_Y1 = static_cast<float>(-(ypos - (this->m_height / 2)) / (this->m_height / 2));
            g_vertices.push_back(Vector3f(g_X1, g_Y1, 0.f));
		}
// 		else
// 		{
// 			g_vertices.clear();
// 		}
        glBindVertexArray(drawableVAO);
		glDrawArrays(GL_LINE_STRIP_ADJACENCY, 0, g_vertices.size());
        glBindVertexArray(0);
    }
	else if (singleDrawMode.getModeState() == DrawMode::CIRCLE_MODE)
	{
        if (g_vertices.size() > 0)
        {
            circle.onPaint(g_vertices[g_vertices.size() - 2],
                    vecDistance(g_vertices[g_vertices.size() - 2]
                              , g_vertices[g_vertices.size() - 1])
                    );
        }
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
	this->m_vbo.init(g_vertices);
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

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H


#include "../include/multibuffer.hpp"
#include "../include/lineshape.h"
#include "../include/circleshape.h"
#include "../include/brush.h"

namespace mlg
{

class  KeyHandler;
struct Vertex;
class  Texture;
class  Brush;

class RenderWindow
{
	friend KeyHandler;
public:
	 RenderWindow(int width, int height, const char* windowName);
	~RenderWindow();

	 void draw();	 
	 void close()   const;
	 void create();
	 bool isOpen()  const;
	 void display() const;
	 




     void draw(const Texture& texture, CircleShape& circle) const;
	 void draw(const Vertex* vertices) const;
	 void draw(Brush& brush);
	 

	 
	 void setBgColor(const float& r, const float& g, const float& b, const float& a) const noexcept;
	 GLFWwindow* getGLFWwindow() const noexcept;
protected:
	 bool gladLoad() const;
public:
	 int             m_width;
	 int             m_height;
	 const char*     m_cWindowName;
	 GLFWwindow*     m_window;

	 Brush*			 m_brush;
	 LineShape*		 m_lineShape;
	 CircleShape*    m_circleShape;
	//VertexBufferArray	m_vbo;
};

} // namespace mlg

#endif // RENDERWINDOW_H

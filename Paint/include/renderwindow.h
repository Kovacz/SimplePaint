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
     void draw(Texture& texture);
     void draw(const Vertex* vertices);
	 void close()   const;
	 void create();
	 bool isOpen()  const;
	 void display() const;
	 	 
	 void setBgColor(const float& r, const float& g, const float& b, const float& a) const noexcept;
	 GLFWwindow* getGLFWwindow() const noexcept;
protected:
	 bool gladLoad() const;
private:
	 int             m_width;
	 int             m_height;
	 const char*     m_cWindowName;
	 GLFWwindow*     m_window;
public:
	 Brush*			 m_brush;
	 LineShape*		 m_lineShape;
	 CircleShape*    m_circleShape;
};

} // namespace mlg

#endif // RENDERWINDOW_H

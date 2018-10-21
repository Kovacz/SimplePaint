#ifndef BRUSH_H
#define BRUSH_H

#include "../include/defines.hpp"
#include "../include/multibuffer.hpp"

namespace mlg
{

class RenderWindow;

class Brush
{
public:
	 Brush();
	~Brush();	
	 void updateBuffers();
	 void startPaint() const;
	 void pullVertices(GLFWwindow* window);
private:
	 double		  m_positionX;
	 double		  m_positionY;
	 VertexArray  m_vertices;
	 IndexesArray m_indexes;
	 MultiBuffer<VBO, VAO, EBO>	m_mulBuff;
};

} // namespace mlg

#endif // BRUSH_H

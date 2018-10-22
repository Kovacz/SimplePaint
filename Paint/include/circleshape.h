#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

#include "../include/defines.hpp"
#include "../include/multibuffer.hpp"

namespace mlg
{

class CircleShape
{
public:
     CircleShape();
	~CircleShape();
//    void createSquareForCircle();
	 void render();
	 void calculate();
     void updateBuffers();
protected:
     void genCircle(const Vector3f& view, const float& radius);	
private:
	 VertexArray  m_vertices;
	 IndexesArray m_indexes;
	 MultiBuffer<VBO, VAO, EBO> m_mulBuff;
};

} // namespace mlg

#endif // CIRCLESHAPE_H

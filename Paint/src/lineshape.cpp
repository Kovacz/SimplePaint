#include "glad/glad.h"
#include "../include/lineshape.h"
#include "../include/keyhandler.h"

namespace mlg
{

LineShape::LineShape() 
{
	this->m_mulBuff.generate();
	this->m_mulBuff.init();
}
LineShape::~LineShape()
{

}
void LineShape::updateBuffers()
{
	this->m_mulBuff.update(g_vertices);
}
void LineShape::render() const
{
	glBindVertexArray(this->m_mulBuff.getArrayHandle());
	glDrawArrays(GL_LINES, 0, g_vertices.size());
	glBindVertexArray(0);
}

} // namespace mlg
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
	this->m_mulBuff.update(singleGlobalDefines.linesVertArray);
}
void LineShape::render() const
{
	glBindVertexArray(this->m_mulBuff.getArrayHandle());
	glDrawArrays(GL_LINES, 0, singleGlobalDefines.linesVertArray.size());
	glBindVertexArray(0);
}

} // namespace mlg

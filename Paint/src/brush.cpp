#include "glad/glad.h"
#include "../include/brush.h"
#include "../include/keyhandler.h"
#include "../include/renderwindow.h"

namespace mlg
{

Brush::Brush() : m_positionX(0), m_positionY(0)
{
	this->m_mulBuff.generate();
	this->m_mulBuff.init();
}
Brush::~Brush()
{

}
void Brush::updateBuffers()
{
	this->m_mulBuff.update(this->m_vertices, this->m_indexes);
}
void Brush::pullVertices(GLFWwindow* window)
{
	if (KeyHandler::mouseClicked)
	{
		singleDrawMode.setDrawFlag(true);
		glfwGetCursorPos(window, &this->m_positionX, &this->m_positionY);

		this->m_indexes.push_back(this->m_vertices.size());
		this->m_vertices.push_back(get_2d_ndc_coord(static_cast<float>(this->m_positionX),
			static_cast<float>(this->m_positionY)));
	}
	if (KeyHandler::mouseReleased)
	{
		this->m_indexes.push_back(0xFFFF);
	}
}
void Brush::startPaint() const
{
	glBindVertexArray(this->m_mulBuff.getArrayHandle());
	glEnable(GL_PRIMITIVE_RESTART);
	glPrimitiveRestartIndex(0xFFFF);
	glDrawElements(GL_LINE_STRIP, this->m_indexes.size(), GL_UNSIGNED_INT, reinterpret_cast<void*>(0));
	glDisable(GL_PRIMITIVE_RESTART);
	glBindVertexArray(0);
}

} // namespace mlg
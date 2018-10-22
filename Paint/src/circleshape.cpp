#include "glad/glad.h"
#include "../include/keyhandler.h"
#include "../include/circleshape.h"
#include "../include/defines.hpp"

#include <cmath>
#include <unordered_set>

namespace mlg
{

CircleShape::CircleShape() 
{
	this->m_mulBuff.generate();
	this->m_mulBuff.init();
}
CircleShape::~CircleShape()
{

}
void CircleShape::updateBuffers()
{
	this->m_mulBuff.update(this->m_vertices, this->m_indexes);
}
void CircleShape::render()
{
	glBindVertexArray(this->m_mulBuff.getArrayHandle());
	glEnable(GL_PRIMITIVE_RESTART);
	glPrimitiveRestartIndex(0xFFFF);
	glDrawElements(GL_LINE_STRIP, this->m_indexes.size(), GL_UNSIGNED_INT, reinterpret_cast<void*>(0));
	glDisable(GL_PRIMITIVE_RESTART);
	glBindVertexArray(0);
}
void CircleShape::calculate()
{	
    if (KeyHandler::mouseReleased)
	{
		this->genCircle(Vector3f(g_X1, g_Y1, .0f),
			vecDistance(Vector3f(g_X1, g_Y1, .0f), Vector3f(g_X2, g_Y2, .0f))
		);
	}
}
void CircleShape::genCircle(const Vector3f& view, const float& radius)
{
	for (int i = 0; i <= 100; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(100); // Get the current angle

		float x = radius * cosf(theta); // Calculate the x component
		float y = radius * sinf(theta); // Calculate the y component

		this->m_indexes.push_back(this->m_vertices.size());
		this->m_vertices.push_back(mlg::Vector3f(x + view.x, y + view.y, 0.f));
	}
	this->m_indexes.push_back(0xFFFF);
}

//CircleShape::CircleShape()
//    : m_circleVBO(0)
//    , m_circleVAO(0)
//    , m_circleEBO(0)
//    , m_circleOuterRadius(0)
//    , m_circleShaderProgram("../../src/circle_vert_shader.vert", "../../src/circle_frag_shader.frag")
//{
//    this->createSquareForCircle();
//    this->setAttribs();
//}

//void CircleShape::onPaint(const Vector3f& view, const float& radius)
//{
//    this->m_circleShaderProgram.use();
//    glUniform2f(this->m_viewDimensions, 700, 800);
//    glUniform1f(this->m_circleOuterRadius, radius);
//    glBindVertexArray(this->m_circleVAO);
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//    glBindVertexArray(0);
//    glFlush();
//}

//void CircleShape::setAttribs()
//{
//    int posAttrib = glGetAttribLocation(this->m_circleShaderProgram.getID(), "pos");
//    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(posAttrib);

//    this->m_circleOuterRadius = glGetUniformLocation(this->m_circleShaderProgram.getID(), "outerRadius");
//    this->m_viewDimensions = glGetUniformLocation(this->m_circleShaderProgram.getID(), "viewDimensions");

//    //this->m_circleShaderProgram.use();

//    glBindVertexArray(0);
//}

//void CircleShape::createSquareForCircle()
//{
//    // define vertices for the two triangles
//    float points[] = {
//        -1.0f, -1.0f,
//         1.0f, -1.0f,
//         1.0f,  1.0f,
//        -1.0f,  1.0f
////        -0.2f, -0.2f,
////         0.2f, -0.2f,
////         0.2f,  0.2f,
////        -0.2f,  0.2f
//    };
//    // define the indices for the triangles
//    unsigned elements[] = {
//        0, 1, 2,
//        2, 3, 0
//    };

//    // setup vertex array object
//    glGenVertexArrays(1, &this->m_circleVAO);
//    glBindVertexArray(this->m_circleVAO);
//    // upload vertex data
//    glGenBuffers(1, &this->m_circleVBO);
//    glBindBuffer(GL_ARRAY_BUFFER, this->m_circleVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
//    // upload element data
//    glGenBuffers(1, &this->m_circleEBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_circleEBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);


//}


} // namespace mlg

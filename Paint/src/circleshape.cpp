#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../include/circleshape.h"
#include "../include/defines.hpp"
#include <cmath>

namespace mlg
{

CircleShape::CircleShape()
    : m_circleVBO(0)
    , m_circleVAO(0)
{

}

void CircleShape::redraw()
{
	if (g_vertices.size() > 0)
	{
		this->onPaint(g_vertices[g_vertices.size() - 2],
			vecDistance(g_vertices[g_vertices.size() - 2]
				, g_vertices[g_vertices.size() - 1])
		);
	}
}

void CircleShape::onPaint(const Vector3f& view, const float& radius)
{
    for (int i = 0; i <= 100; ++i)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle

        float x = radius * cosf(theta);//calculate the x component
        float y = radius * sinf(theta);//calculate the y component

        this->m_circleVert.push_back(mlg::Vector3f(x + view.x, y + view.y, 0.f));
    }
    this->setAttribs();
    glBindVertexArray(this->m_circleVAO);
    glDrawArrays(GL_LINE_LOOP, 0, this->m_circleVert.size());
    glBindVertexArray(0);
    glFlush();
    this->m_circleVert.clear();
}

void CircleShape::setAttribs()
{
    // setup vertex array object
    glGenVertexArrays(1, &this->m_circleVAO);
    glBindVertexArray(this->m_circleVAO);
    // upload vertex data
    glGenBuffers(1, &this->m_circleVBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_circleVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3) * this->m_circleVert.size(), &this->m_circleVert[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
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

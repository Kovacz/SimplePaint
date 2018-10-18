#include <glad/glad.h>
#include <iostream>
#include "../include/vector2.hpp"
#include "../include/vector3.hpp"
#include "../include/vertex.h"
#include "../include/vertexbuffer.h"

namespace mlg
{

VertexBuffer::VertexBuffer() : m_VboId(0), m_VaoId(0), m_bufferSize(0)
{}

VertexBuffer::~VertexBuffer()
{
    if (this->m_VboId)
	{
		///
	}
}

bool VertexBuffer::init(const Vertex3& vertices)
{
    glGenVertexArrays(1, &this->m_VaoId);
    glGenBuffers(1, &this->m_VboId);
    glBindVertexArray(this->m_VaoId);

    glBindBuffer(GL_ARRAY_BUFFER, this->m_VboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

	this->m_bufferSize = vertices.size();
	return true;
}

bool VertexBuffer::init(const Vertex* vertices, std::size_t vertexCount)
{
    glGenBuffers(1, &this->m_VboId);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_VboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(Vector2f), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	this->m_bufferSize = vertexCount;
	return true;
}

unsigned int VertexBuffer::getVAOHandle() const noexcept
{
    return this->m_VaoId;
}

unsigned int VertexBuffer::getVBOHandle() const noexcept
{
    return this->m_VboId;
}

std::size_t VertexBuffer::getVertexCount() const noexcept
{
	return this->m_bufferSize;
}

void VertexBuffer::update(const Vertex3& vertices) const
{
    glBindBuffer(GL_ARRAY_BUFFER, this->m_VboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::update(const Vertex* vertices, std::size_t vertexCount) const
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::bind(const VertexBuffer* vertexBuffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer ? vertexBuffer->m_VboId : 0);
}

}

#include <glad/glad.h>
#include <iostream>
#include "../include/vertex.h"
#include "../include/vertexbuffer.h"
using mlg::VertexBuffer;

VertexBuffer::VertexBuffer() : m_VBO(0), m_VAO(0), m_bufferSize(0)
{}

VertexBuffer::~VertexBuffer()
{
    if (this->m_VBO && this->m_VAO)
    {
        ///
    }
}

bool VertexBuffer::create(const Vertex* vertices, std::size_t vertexCount)
{
    glGenVertexArrays(1, &this->m_VAO);
    glGenBuffers(1, &this->m_VBO);
    glBindVertexArray(this->m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertices, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 2 * sizeof(Vector2f), reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    this->m_bufferSize = vertexCount;
    return true;
}

unsigned int VertexBuffer::getVBOHandle() const
{
    return this->m_VBO;
}

unsigned int VertexBuffer::getVAOHandle() const
{
    return this->m_VAO;
}

std::size_t VertexBuffer::getVertexCount() const
{
    return this->m_bufferSize;
}

void VertexBuffer::bind(const VertexBuffer* vertexBuffer)
{
    if (vertexBuffer)
        glBindVertexArray(vertexBuffer->m_VAO);
    return;
}

void VertexBuffer::unbind(const VertexBuffer* vertexBuffer)
{
    if (vertexBuffer)
        glBindVertexArray(0);
    return;
}

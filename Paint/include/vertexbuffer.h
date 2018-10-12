#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <cstddef>

namespace mlg
{
class Vertex;

class VertexBuffer
{
public:
    VertexBuffer();
    //VertexBuffer(PrimitiveType type, Usage usage);
   ~VertexBuffer();

    bool        create(const Vertex* vertices, std::size_t vertexCount);
    unsigned    getVBOHandle() const;
    unsigned    getVAOHandle() const;
    std::size_t getVertexCount()  const;
    static void bind(const VertexBuffer* vertexBuffer);
    static void unbind(const VertexBuffer* vertexBuffer);
private:
    unsigned    m_VBO;
    unsigned    m_VAO;
    std::size_t m_bufferSize;
};

} // namespace mlg

#endif // VERTEXBUFFER_H

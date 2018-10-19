#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <cstddef>
#include "../include/defines.hpp"

namespace mlg
{
struct Vertex;

class VertexBuffer
{
public:
    VertexBuffer();
    //VertexBuffer(Usage usage);
   ~VertexBuffer();

    unsigned    getVBOHandle() const noexcept;
    unsigned    getVAOHandle() const noexcept;
    std::size_t getVertexCount()  const noexcept;

    bool        init(const Vertex* vertices, std::size_t vertexCount);
    bool        init(const VertexArray3f& vertices);
    void		update(const Vertex* vertices, std::size_t vertexCount) const;
    void		update(const VertexArray3f& vertices) const;

    static void bind(const VertexBuffer* vertexBuffer);
private:
    unsigned    m_VboId;
    unsigned    m_VaoId;
    std::size_t m_bufferSize;
};

} // namespace mlg

#endif // VERTEXBUFFER_H

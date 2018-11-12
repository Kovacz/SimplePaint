#pragma once

#include <glad/glad.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace mlg
{

namespace Graphics
{

enum BufferTypes
{
	VBO   = 0x8892,
	VAO   = 0x386C,
	EBO   = 0x8893,
	Undef = 0x0000,
};

template <BufferTypes T, BufferTypes ...Args>
class MultiBuffer final
{
public:
    MultiBuffer();
    ~MultiBuffer() noexcept;
    // TODO: in future realize this logic
    MultiBuffer(MultiBuffer&&) = delete;
    MultiBuffer(MultiBuffer const&) = delete;
    MultiBuffer& operator=(MultiBuffer&&) = delete;
    MultiBuffer& operator=(MultiBuffer const&) = delete;
    // TODO: add more functionality?
    template <typename U>
    void setBufferData(BufferTypes type, std::vector<U> container) const noexcept;
    void setAttribPointer(uint32_t index, int size, uint32_t offset) const noexcept;
private:    
    // inherit call
    template <BufferTypes ...Other>
    void initialize() noexcept;
    void initialize(BufferTypes types) noexcept;
    // generating only chosen buffers
    void generateVbo() noexcept;
    void generateVao() noexcept;
    void generateEbo() noexcept;
public:
    static void bind(MultiBuffer* p_mBuff);
	static void unbind(MultiBuffer* p_mBuff);
private:
    bool     m_bindState;
    uint32_t m_vboHandler;
	uint32_t m_vaoHandler;
	uint32_t m_eboHandler;
};

template<BufferTypes T, BufferTypes ...Args>
inline MultiBuffer<T, Args...>::MultiBuffer()
    : m_vboHandler(0)
    , m_vaoHandler(0)
    , m_eboHandler(0)
    , m_bindState(false)
{
	this->initialize<T, Args...>();
}

template<BufferTypes T, BufferTypes ...Args>
inline MultiBuffer<T, Args...>::~MultiBuffer() noexcept
{
	glDeleteVertexArrays(1, &m_vboHandler);
	glDeleteBuffers(1, &m_vaoHandler);
	glDeleteBuffers(1, &m_eboHandler);
}

template<BufferTypes T, BufferTypes ...Args>
template<BufferTypes ...Other>
inline void MultiBuffer<T, Args...>::initialize() noexcept
{
	(this->initialize(Other), ...);
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::initialize(BufferTypes types) noexcept
{
	if (types == BufferTypes::VBO) {
		this->generateVbo();
    }
	else if (types == BufferTypes::VAO) {
		this->generateVao();
    }
	else if (types == BufferTypes::EBO) {
		this->generateEbo();
    }
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::generateVbo() noexcept
{
	glGenBuffers(1, &m_vboHandler);
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::generateVao() noexcept
{
	glGenVertexArrays(1, &m_vaoHandler);
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::generateEbo() noexcept
{
	glGenBuffers(1, &m_eboHandler);
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::setAttribPointer(uint32_t index, int size, uint32_t offset) const noexcept
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void*>(offset));
	glEnableVertexAttribArray(true);
}

template<BufferTypes T, BufferTypes ...Args>
template <typename U>
inline void MultiBuffer<T, Args...>::setBufferData(BufferTypes type, std::vector<U> container) const noexcept
{
	glBufferData(type, container.size() * sizeof(U), container.data(), GL_STATIC_DRAW);
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::bind(MultiBuffer* p_mBuff)
{
    if (!p_mBuff->m_bindState) {
		glBindVertexArray(p_mBuff->m_vboHandler);
		glBindBuffer(GL_ARRAY_BUFFER, p_mBuff->m_vaoHandler);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_mBuff->m_eboHandler);
		p_mBuff->m_bindState = true;
    }
}

template<BufferTypes T, BufferTypes ...Args>
inline void MultiBuffer<T, Args...>::unbind(MultiBuffer* p_mBuff)
{
    if (p_mBuff->m_bindState) {
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		p_mBuff->m_bindState = false;
    }
}

} // namespace Graphics

} // namespace mlg

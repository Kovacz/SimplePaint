// #include <glad/glad.h>
// #include "../include/multibuffer.h"
// 
// namespace mlg
// {
// 
// template<BufferTypes T, BufferTypes ...Args>
// MultiBuffer<T, Args...>::MultiBuffer()
// 		: m_vertexBuffHandler(0)
// 		, m_vertexArrayHandler(0)
// 		, m_elementBuffHandler(0)
// {
// 	this->generate<T, Args...>();
// }
// template<BufferTypes T, BufferTypes ...Args>
// MultiBuffer<T, Args...>::~MultiBuffer()
// {
// 	glDeleteVertexArrays(1, &this->m_vertexArrayHandler);
// 	glDeleteBuffers(1, &this->m_vertexBuffHandler);
// 	glDeleteBuffers(1, &this->m_elementBuffHandler);
// }
// template<BufferTypes T, BufferTypes ...Args>
// template<BufferTypes ...Ot>
// void MultiBuffer<T, Args...>::generate()
// {
// 	(this->generate(Ot), ...);
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::generate(BufferTypes X)
// {
// 	if (X == BufferTypes::VBO)
// 		this->initVertexBuffer();
// 	else if (X == BufferTypes::VAO)
// 		this->initVertexArray();
// 	else if (X == BufferTypes::EBO)
// 		this->initElementBuffer();
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::initVertexBuffer()
// {
// 	glGenBuffers(1, &this->m_vertexBuffHandler);
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::initVertexArray()
// {
// 	glGenVertexArrays(1, &this->m_vertexArrayHandler);
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::initElementBuffer()
// {
// 	glGenBuffers(1, &this->m_elementBuffHandler);
// }
// template<BufferTypes T, BufferTypes ...Args>
// bool MultiBuffer<T, Args...>::init() const
// {
// 	MultiBuffer::bind(this);
// 		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void*>(0));
// 		glEnableVertexAttribArray(0);
// 	MultiBuffer::unbind(this);
// 
// 	return true;
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::bind(const MultiBuffer* p_mBuff)
// {
// 	if (p_mBuff->m_vertexArrayHandler != 0)
// 		glBindVertexArray(p_mBuff->m_vertexArrayHandler);
// 	if (p_mBuff->m_vertexBuffHandler != 0)
// 		glBindBuffer(GL_ARRAY_BUFFER, p_mBuff->m_vertexBuffHandler);
// 	if (p_mBuff->m_elementBuffHandler != 0)
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, p_mBuff->m_elementBuffHandler);
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::unbind(const MultiBuffer* p_mBuff)
// {
// 	if (p_mBuff->m_vertexArrayHandler != 0)
// 		glBindVertexArray(0);
// 	if (p_mBuff->m_vertexBuffHandler != 0)
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 	if (p_mBuff->m_elementBuffHandler != 0)
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
// }
// template<BufferTypes T, BufferTypes ...Args>
// void MultiBuffer<T, Args...>::update(const VertexArray& vertices, const IndexesArray& indexes /*= nullptr*/) const
// {
// 	if (this->m_vertexBuffHandler != 0)
// 	{
// 		glBindBuffer(GL_ARRAY_BUFFER, this->m_vertexBuffHandler);
// 		glBufferData(GL_ARRAY_BUFFER, static_cast<int>(vertices.size() * sizeof(mlg::Vector3f)), vertices.data(), GL_DYNAMIC_DRAW);
// 		glBindBuffer(GL_ARRAY_BUFFER, 0);
// 	}
// 	if (this->m_elementBuffHandler != 0)
// 	{
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_elementBuffHandler);
// 		glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<int>(indexes.size() * sizeof(unsigned)), indexes.data(), GL_DYNAMIC_DRAW);
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
// 	}
// }
// template<BufferTypes T, BufferTypes ...Args>
// unsigned MultiBuffer<T, Args...>::getBufferHandle() const noexcept
// {
// 	if (this->m_vertexBuffHandler != 0)
// 		return this->m_vertexBuffHandler;
// 	return 0;
// }
// template<BufferTypes T, BufferTypes ...Args>
// unsigned MultiBuffer<T, Args...>::getArrayHandle() const noexcept
// {
// 	if (this->m_vertexArrayHandler != 0)
// 		return this->m_vertexArrayHandler;
// 	return 0;
// }
// template<BufferTypes T, BufferTypes ...Args>
// unsigned MultiBuffer<T, Args...>::getElementHandle() const noexcept
// {
// 	if (this->m_elementBuffHandler != 0)
// 		return this->m_elementBuffHandler;
// 	return 0;
// }
// 
// } // namespace mlg

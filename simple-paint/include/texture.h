#pragma once

#include <utility>
#include "multibuffer.hpp"

namespace mlg
{

namespace Graphics
{

class Texture
{
	using byte = unsigned char;
	using info = std::pair<int, int>;
public:
	Texture();
	~Texture() noexcept;
	// TODO: in future realize this logic
	Texture(Texture &&) = delete;
	Texture(Texture const &) = delete;
	Texture &operator=(Texture &&) = delete;
	Texture &operator=(Texture const &) = delete;
	// TODO: make sure about all noexcept here
	void generate() noexcept;
	bool loadFromFile(char const *path) noexcept;
	// more getters...
	info getInfo() const noexcept;
	byte *getImage() const noexcept;
	unsigned getHandle() const noexcept;
public:
	static void bind(Texture const *texture);
private:
	byte *m_data;
	int m_width;
	int m_height;
	int m_nrChannels;
	unsigned m_handle;
private:
	std::vector<float> m_vertices{
		// Positions          // Colors           // Texture Coords
		-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};
	std::vector<uint8_t> m_indexes{
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
private:
	// VAO, VBO, EBO
	Graphics::MultiBuffer<VBO, VAO, EBO> m_buff;
};

} // namespace Graphics

} // namespace mlg

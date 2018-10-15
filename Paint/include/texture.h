#ifndef TEXTURE_H
#define TEXTURE_H

namespace mlg
{

class Texture
{
public:
	Texture();
   ~Texture();

    void update() const;
	void generate() const;
	void setTexParametri() const;
	unsigned getNativeHandle() const noexcept;
	static void bind(const Texture* texture);
private:
	unsigned	m_textureID;
	float		m_vertices[32] =
	{
		// Positions         // Colors           // Texture Coords
		-1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // Top Right
		 1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // Bottom Right
		 1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
		-1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // Top Left 
	};
	unsigned	m_indices[6] =
	{
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};
};

} // namespace mlg

#endif // TEXTURE_H
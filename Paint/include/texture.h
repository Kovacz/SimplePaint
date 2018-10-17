#ifndef TEXTURE_H
#define TEXTURE_H

namespace mlg
{

class Texture
{
	typedef unsigned char byte;
public:
	Texture();
	Texture(const char* texture_path);
   ~Texture();

    void update() const;
	void generate() const;
	unsigned getNativeHandle() const noexcept;
	unsigned getWidth() const noexcept;
	unsigned getHeight() const noexcept;
	static void bind(const Texture* texture);
protected:
	void create();
    void setTexParametri();
private:
	byte*		m_data;
	int			m_width;
	int			m_height;
	int			m_nrChannels;
	unsigned	m_textureID;
	float		m_vertices[32] =
	{
		 // Positions         // Colors           // Texture Coords
		-1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, 
		-1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, 
		 1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f  
	};
	unsigned	m_indices[6] =
	{
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

};

} // namespace mlg

#endif // TEXTURE_H

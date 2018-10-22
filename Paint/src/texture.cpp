//#include "glad/glad.h"
#include "../include/texture.h"
#include "../include/defines.hpp"
//#define  STB_IMAGE_IMPLEMENTATION
//#include "../libs/stb_image.h"
#include <iostream>
#include <stdio.h>
#include "../libs/SOIL/inc/SOIL/SOIL.h"

namespace mlg
{

Texture::Texture() : m_data(nullptr), m_width(0), m_height(0), m_nrChannels(0), m_textureID(0)
{
	this->create();
    this->setTexParametri();
}
Texture::Texture(const char* texture_path) : m_data(nullptr), m_width(0), m_height(0), m_nrChannels(0), m_textureID(0)
{
	this->create();
	this->setTexParametri();
    //stbi_set_flip_vertically_on_load(true);
    this->m_data = SOIL_load_image(texture_path, &this->m_width, &this->m_height, &this->m_nrChannels, 0);
	if (this->m_data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->m_width, this->m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->m_data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
        std::cerr << "Failed to load texture" << std::endl;
	}
}
Texture::~Texture()
{
    if (this->m_data != nullptr)
        SOIL_free_image_data(this->m_data);
}
unsigned Texture::getWidth() const noexcept
{
	return this->m_width;
}
unsigned Texture::getHeight() const noexcept
{
	return this->m_height;
}
void Texture::create()
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->m_vertices), this->m_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->m_indices), this->m_indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Texture::save()
{
    std::vector<byte> image(WIDTH * HEIGHT * 3);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, image.data());
    SOIL_save_image("saved.bmp", SOIL_SAVE_TYPE_BMP, WIDTH, HEIGHT, 3, image.data());
}
void Texture::update() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}
void Texture::generate()
{
    m_data = new byte[WIDTH * HEIGHT * 4];
	for (size_t i = 0; i < WIDTH * HEIGHT * 4; ++i)
        m_data[i] = 255;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, WIDTH, HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
	glGenerateMipmap(GL_TEXTURE_2D);
}
void Texture::render() const
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
void Texture::setTexParametri()
{
	// Generate texture
	glGenTextures(1, &this->m_textureID);
	glBindTexture(GL_TEXTURE_2D, this->m_textureID);
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
unsigned Texture::getNativeHandle() const noexcept
{
	return this->m_textureID;
}
void Texture::bind(const Texture* texture)
{
	glBindTexture(GL_TEXTURE_2D, texture ? texture->getNativeHandle() : 0);
}


}

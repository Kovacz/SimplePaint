#include "texture.h"
#include "SOIL.h"
#include <iostream>

namespace mlg
{

namespace Graphics
{

Texture::Texture()
    : m_data(nullptr), m_width(0), m_height(0), m_nrChannels(0), m_handle(0)
{
    MultiBuffer<VBO, VAO, EBO>::bind(&m_buff);
    m_buff.setBufferData(VBO, m_vertices);
    m_buff.setBufferData(EBO, m_indexes);
    // set position, color and texture coords attribs
    m_buff.setAttribPointer(0, 3, 0);
    m_buff.setAttribPointer(1, 3, (3 * sizeof(float)));
    m_buff.setAttribPointer(2, 2, (6 * sizeof(float)));
    MultiBuffer<VBO, VAO, EBO>::unbind(&m_buff);
}

Texture::~Texture() noexcept
{
    if (m_data) {
        SOIL_free_image_data(m_data);
    }
}

void Texture::generate() noexcept
{
    // Generate texture
    glGenTextures(1, &m_handle);
    glBindTexture(GL_TEXTURE_2D, m_handle);
    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT (usually basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

bool Texture::loadFromFile(char const *path) noexcept
{
    m_data = SOIL_load_image(path, &m_width, &m_height, &m_nrChannels, 0);
    if (!m_data) {
        std::cerr << "ERROR::TEXTURE 'failed to load texture'" << std::endl;
        return false;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
    glGenerateMipmap(GL_TEXTURE_2D);
    return true;
}

Texture::info Texture::getInfo() const noexcept
{
    return std::make_pair(m_width, m_height);
}

Texture::byte *Texture::getImage() const noexcept
{
    if (!m_data) {
        return nullptr;
    }
    return m_data;
}

unsigned Texture::getHandle() const noexcept
{
    return m_handle;
}

void Texture::bind(const Texture *texture)
{
    glBindTexture(GL_TEXTURE_2D, texture ? texture->getHandle() : 0);
}

} // namespace Graphics

} // namespace mlg

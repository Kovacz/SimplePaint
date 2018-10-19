#include "glad/glad.h"
#include "../include/brush.h"
#include "../include/keyhandler.h"
#include "../include/renderwindow.h"

namespace mlg
{

Brush::Brush()
    : m_VBO(0)
    , m_VAO(0)
    , m_vertArray(0)
    , m_vertIndex(0)
    , m_index(0)
    , m_drawFlag(false)
{
    this->init();
}
Brush::~Brush()
{
    glDeleteVertexArrays(1, &this->m_VAO);
    glDeleteBuffers(1, &this->m_VBO);
}
void Brush::init()
{
    glGenVertexArrays(1, &this->m_VAO);
    glGenBuffers(1, &this->m_VBO);
    glGenBuffers(1, &this->m_EBO);

    glBindVertexArray(this->m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexArray3f), this->m_vertArray.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IndexArray), this->m_vertIndex.data(), GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void Brush::update()
{
    glBindBuffer(GL_ARRAY_BUFFER, this->m_VBO);
    glBufferData(GL_ARRAY_BUFFER,
        static_cast<int>(this->m_vertArray.size() * sizeof(VertexArray3f)),
        this->m_vertArray.data(),
        GL_DYNAMIC_DRAW
    );
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void*>(0));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
        static_cast<int>(this->m_vertIndex.size() * sizeof(IndexArray)),
        this->m_vertIndex.data(),
        GL_DYNAMIC_DRAW
    );
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void Brush::draw()
{
    if (m_drawFlag)
    {
        glBindVertexArray(m_VAO);
        glEnable(GL_PRIMITIVE_RESTART);
        glPrimitiveRestartIndex(0xFFFF);
        glDrawElements(GL_LINE_STRIP,
            static_cast<int>(this->m_vertIndex.size() - 1),
            GL_UNSIGNED_INT,
            reinterpret_cast<void*>(0)
        );
        glDisable(GL_PRIMITIVE_RESTART);
        glBindVertexArray(0);
    }
}
void Brush::startDraw(const RenderWindow& window)
{
    if (singleDrawMode.getModeState() == DrawMode::BRUSH_MODE)
    {
        if (KeyHandler::mouseClicked)
        {
            singleDrawMode.setDrawFlag(true);
            double xpos = .0, ypos = .0;
            glfwGetCursorPos(window.m_window, &xpos, &ypos);
            this->m_vertArray.push_back(Vector3f(
                static_cast<float>( (xpos - (WIDTH  / 2)) / (WIDTH  / 2)),
                static_cast<float>(-(ypos - (HEIGHT / 2)) / (HEIGHT / 2)),
                0.f));
            this->m_vertIndex.push_back(this->m_index++);
        }
        else if (KeyHandler::mouseRelease)
        {
            this->m_vertIndex.push_back(0xFFFF);
            this->m_drawFlag = true;
        }

        this->draw();
    }
}

} // namespace mlg

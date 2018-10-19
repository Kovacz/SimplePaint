#ifndef BRUSH_H
#define BRUSH_H

#include "../include/defines.hpp"

namespace mlg
{

class RenderWindow;

class Brush
{
    typedef std::vector<int> IndexArray;
public:
    Brush();
   ~Brush();
    void init();
    void update();
    void startDraw(const RenderWindow& window);
protected:
    void draw();
private:
    unsigned        m_VBO;
    unsigned        m_VAO;
    unsigned        m_EBO;
    VertexArray3f   m_vertArray;
    IndexArray      m_vertIndex;
    int             m_index;
    bool            m_drawFlag;
};

} // namespace mlg

#endif // BRUSH_H

#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H
#include "../include/shader.h"
#include "../include/vector3.hpp"
#include <vector>
namespace mlg
{

class CircleShape
{
public:
    CircleShape();

//    void createSquareForCircle();
    void setAttribs();
    void onPaint(const Vector3f& view, const float& radius);
private:
    unsigned    m_circleVBO;
    unsigned    m_circleVAO;
    std::vector<Vector3f> m_circleVert;
//    unsigned    m_circleEBO;
//    int         m_circleOuterRadius;
//    int         m_viewDimensions;
//    Shader      m_circleShaderProgram;
};

} // namespace mlg

#endif // CIRCLESHAPE_H

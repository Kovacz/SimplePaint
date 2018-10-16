#ifndef VERTEX_H
#define VERTEX_H
#include "../include/vector2.hpp"
#include "../include/vector3.hpp"

namespace mlg
{

struct Vertex
{
    Vertex();
	Vertex(const Vector2f& pos);
    Vertex(const Vector2f& pos, const Vector2f& texCoords);
    ////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////
    Vector2f  position;
    //Color     color;
    Vector2f  textureCoords;
};

} // namespace mlg

#endif // VERTEX_H

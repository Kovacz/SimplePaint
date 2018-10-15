#include "include/vertex.h"

namespace mlg
{

Vertex::Vertex() : position(0, 0), textureCoords(0, 0)
{}

Vertex::Vertex(const Vector2f& pos) : position(pos), textureCoords(0, 0)
{}

Vertex::Vertex(const Vector2f& pos, const Vector2f& texCoords)
	: position(pos)
	, textureCoords(texCoords)
{}

}

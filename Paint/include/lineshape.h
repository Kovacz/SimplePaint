#ifndef LINESHAPE_H
#define LINESHAPE_H

#include "../include/defines.hpp"
#include "../include/multibuffer.hpp"
#include "../include/vector3.hpp"

namespace mlg
{

class LineShape
{
public:
	 LineShape();
	~LineShape();
	 void render() const;
	 void updateBuffers();
private:
	 MultiBuffer<VBO, VAO> m_mulBuff;
};

} // namespace mlg

#endif // LINESHAPE_H

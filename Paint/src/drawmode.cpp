#include "../include/drawmode.h"

namespace mlg
{

DrawMode &DrawMode::getInstance()
{
	static DrawMode instance;
	return instance;
}

DrawMode::DrawMode() : m_state(UNDEFINED), m_drawFlag(false)
{
	/*...*/
}

DrawMode::~DrawMode()
{
	/*...*/
}

void DrawMode::setMode(const Mods& mod) noexcept
{
	if (this->m_state != mod)
		this->m_state = mod;
	return;
}

void DrawMode::setDrawFlag(const bool& flag) noexcept
{
	this->m_drawFlag = flag;
}

DrawMode::Mods DrawMode::getModeState() const noexcept
{
	return this->m_state;
}

bool DrawMode::getDrawFlagState() const noexcept
{
	return this->m_drawFlag;
}

}

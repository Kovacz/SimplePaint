#include "../include/GlobalDefines.h"

namespace mlg
{

GlobalDefines &GlobalDefines::getInstance()
{
	static GlobalDefines instance;
	return instance;
}

GlobalDefines::GlobalDefines() 
		: m_state(UNDEFINED)
		, m_drawFlag(false)
		, mouseClickedCoords(0.f, 0.f, 0.f)
		, mouseReleasedCoords(0.f, 0.f, 0.f)
{
	/*...*/
}

GlobalDefines::~GlobalDefines()
{
	/*...*/
}

void GlobalDefines::setMode(const DrawMods& mod) noexcept
{
	if (this->m_state != mod)
		this->m_state = mod;
	return;
}

void GlobalDefines::setDrawFlag(const bool& flag) noexcept
{
	this->m_drawFlag = flag;
}

GlobalDefines::DrawMods GlobalDefines::getModeState() const noexcept
{
	return this->m_state;
}

bool GlobalDefines::getDrawFlagState() const noexcept
{
	return this->m_drawFlag;
}

}

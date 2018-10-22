#ifndef GLOBALDEFINES_H
#define GLOBALDEFINES_H

#include <vector>
#include "../include/vector3.hpp"

namespace mlg
{

class GlobalDefines
{
	typedef std::vector<Vector3f> VertexArray;
public:
	enum DrawMods
	{
		LINES_MODE,
		LINES_STRIP_MODE,
		BRUSH_MODE,
        CIRCLE_MODE,
        LOAD_BG_MODE,
        SAVE_MODE,
        UNDEFINED,
	};
private:
	GlobalDefines();
   ~GlobalDefines();
    GlobalDefines(const GlobalDefines&)            = delete;
	GlobalDefines &operator=(const GlobalDefines&) = delete;
public:
	void	 setMode(const DrawMods& mod)   noexcept;
	void	 setDrawFlag(const bool& flag)  noexcept;
	DrawMods getModeState()			  const noexcept;
	bool	 getDrawFlagState()       const noexcept;
	// -__-
	static GlobalDefines& getInstance();
private:
	DrawMods m_state;
	bool     m_drawFlag;
public:
	// states
    bool	 lines_mode   = false;
    bool	 brush_mode   = false;
    bool	 circle_mode  = false;
    bool	 texture_mode = false;
	// 
	VertexArray  linesVertArray;
	Vector3f	 mouseClickedCoords;
	Vector3f	 mouseReleasedCoords;
};

} // namespace mlg

#endif // GLOBALDEFINES_H

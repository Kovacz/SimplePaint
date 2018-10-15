#ifndef DRAWMODE_H
#define DRAWMODE_H

namespace mlg
{

class DrawMode
{
public:
	enum Mods
	{
		LINES_MODE,
		LINES_STRIP_MODE,
		BRUSH_MODE,
		CIRCLE_MODE
	};
private:
	DrawMode();
   ~DrawMode();
	DrawMode(DrawMode const&)            = delete;
	DrawMode &operator=(DrawMode const&) = delete;
public:
	void   setMode(const Mods& mod)       noexcept;
	void   setDrawFlag(const bool& flag)  noexcept;
	Mods   getModeState()			const noexcept;
	bool   getDrawFlagState()       const noexcept;
	// -__-
	static DrawMode& getInstance();
private:
	Mods   m_state;
	bool   m_drawFlag;
};

} // namespace mlg

#endif // DRAWMODE_H
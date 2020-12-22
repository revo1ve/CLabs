#pragma once

class MCell
{
	friend class Maze;
public:
	bool right() { return m_right; }
	bool down() { return m_down; }
private:
	MCell() { m_down = false; m_right = false; }
	bool m_down;
	bool m_right;
};

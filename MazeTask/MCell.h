#pragma once

class MCell
{
	friend class Maze;
private:
	bool m_down;
	bool m_right;
	MCell();
public:
	bool right();
	bool down();
};

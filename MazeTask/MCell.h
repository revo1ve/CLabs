#pragma once

class MCell
{
	friend class Maze;
public:
	bool right();
	bool down();
private:
	MCell();
	bool m_down;
	bool m_right;
};

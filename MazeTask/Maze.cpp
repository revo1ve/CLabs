#include "Maze.h"

MCell::MCell()
{
	m_down = false;
	m_right = false;
}

Maze::Maze(int n, int m) 
{ 
	n = n + 2;
	m = m + 2;
	m_field = new MCell[n * m];
	m_n = n;
	m_m = m;
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (!cellInMaze(i1, j1) || !cellInMaze(i2, j2)) return false;

	if (j1 < j2) return m_field[i1 * m_n + j1].m_right;

	else if (j1 > j2) return m_field[i2 * m_n + j2].m_right;

	else if (i1 < i2) return m_field[i1 * m_n + j1].m_down;

	else return m_field[i2 * m_n + j2].m_down;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	i1 = i1 + 1;
	j1 = j1 + 1;
	i2 = i2 + 1;
	j2 = j2 + 1;

	if (!cellInMaze(i1, j1) || !cellInMaze(i2, j2)) return false;

	if (j1 < j2) m_field[i1 * m_n + j1].m_right = true;

	else if (j1 > j2) m_field[i2 * m_n + j2].m_right = true;

	else if (i1 < i2) m_field[i1 * m_n + j1].m_down = true;

	else m_field[i2 * m_n + j2].m_down = true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	i1 = i1 + 1;
	j1 = j1 + 1;
	i2 = i2 + 1;
	j2 = j2 + 1;

	if (!cellInMaze(i1, j1) || !cellInMaze(i2, j2)) return false;

	if (j1 < j2) m_field[i1 * m_n + j1].m_right = false;

	else if (j1 > j2) m_field[i2 * m_n + j2].m_right = false;

	else if (i1 < i2) m_field[i1 * m_n + j1].m_down = false;

	else m_field[i2 * m_n + j2].m_down = false;
}

void Maze::printMaze()
{
	bool left = false;
	bool up = false;
	bool right = false;
	bool down = false;

	for (int i = 1; i < m_n - 1; i++)
	{
		for (int j = 1; j < m_m - 1; j++)
		{
			if (hasConnection(i, j, i, j - 1))
				left = true;
			if (hasConnection(i, j, i - 1, j))
				up = true;
			if (hasConnection(i, j, i, j + 1))
				right = true;
			if (hasConnection(i, j, i + 1, j))
				down = true;

			if (left && up && right && down)
				cout << static_cast<char>(197);
			else if (left && up && right)
				cout << static_cast<char>(193);
			else if (left && up && down)
				cout << static_cast<char>(180);
			else if (left && right && down)
				cout << static_cast<char>(194);
			else if (up && right && down)
				cout << static_cast<char>(195);
			else if (left && up)
				cout << static_cast<char>(217);
			else if (up && right)
				cout << static_cast<char>(192);
			else if (left && down)
				cout << static_cast<char>(191);
			else if (right && down)
				cout << static_cast<char>(218);
			else if (up && down)
				cout << static_cast<char>(179);
			else if (left && right)
				cout << static_cast<char>(196);
			else
				cout << '0';

			left = false;
			up = false;
			right = false;
			down = false;
		}

		cout << "\n";
	}
}


Maze* createLadderMaze(int n, int j)
{
	Maze* ladderMaze = new Maze(5, 5);

	ladderMaze->makeConnection(0, 0, 0, 1);
	ladderMaze->makeConnection(0, 1, 1, 1);
	ladderMaze->makeConnection(1, 1, 1, 2);
	ladderMaze->makeConnection(1, 2, 2, 2);
	ladderMaze->makeConnection(2, 2, 2, 3);
	ladderMaze->makeConnection(2, 3, 3, 3);
	ladderMaze->makeConnection(3, 3, 3, 4);
	ladderMaze->makeConnection(3, 4, 4, 4);
	ladderMaze->makeConnection(4, 4, 4, 5);

	return ladderMaze;
}

Maze::~Maze() { free(m_field); }

bool MCell::down() { return m_down; }

bool MCell::right() { return m_right; }

const MCell& Maze::cell(int i, int j) const { return *m_field; }

bool Maze::cellInMaze(int i, int j) { return i >= 0 && i < m_n&& j >= 0 && j < m_m; }

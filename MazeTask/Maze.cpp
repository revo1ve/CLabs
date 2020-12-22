#include "Maze.h"

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (!cellInMaze(i1, j1) || !cellInMaze(i2, j2)) return false;

	if (j1 < j2) return m_field[i1 * m_m + j1].m_right;

	else if (j1 > j2) return m_field[i2 * m_m + j2].m_right;

	else if (i1 < i2) return m_field[i1 * m_m + j1].m_down;

	else return m_field[i2 * m_m + j2].m_down;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (!cellInMaze(i1, j1) || !cellInMaze(i2, j2)) return false;

	if (j1 < j2) m_field[i1 * m_m + j1].m_right = true;

	else if (j1 > j2) m_field[i2 * m_m + j2].m_right = true;

	else if (i1 < i2) m_field[i1 * m_m + j1].m_down = true;

	else m_field[i2 * m_m + j2].m_down = true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (!cellInMaze(i1, j1) || !cellInMaze(i2, j2)) return false;

	if (j1 < j2) m_field[i1 * m_m + j1].m_right = false;

	else if (j1 > j2) m_field[i2 * m_m + j2].m_right = false;

	else if (i1 < i2) m_field[i1 * m_m + j1].m_down = false;

	else m_field[i2 * m_m + j2].m_down = false;
}

void Maze::printMaze()
{
	bool left = false;
	bool up = false;
	bool right = false;
	bool down = false;

	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_m; j++)
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
				cout << (char)197;
			else if (left && up && right)
				cout << (char)193;
			else if (left && up && down)
				cout << (char)180;
			else if (left && right && down)
				cout << (char)194;
			else if (up && right && down)
				cout << (char)195;
			else if (left && up)
				cout << (char)217;
			else if (up && right)
				cout << (char)192;
			else if (left && down)
				cout << (char)191;
			else if (right && down)
				cout << (char)218;
			else if (up && down)
				cout << (char)179;
			else if (left && right)
				cout << (char)196;
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

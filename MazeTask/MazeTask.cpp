#include "Maze.h"

int main()
{
	Maze* ladderMaze = new Maze(5, 5);

	for (int i = 0; i < 5; i++)
	{
		ladderMaze->makeConnection(i - 1, i, i, i);
		ladderMaze->makeConnection(i, i, i, i + 1);
	}

	ladderMaze->printMaze();
}

#include "Maze.h"

int main()
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

	ladderMaze->printMaze();
}

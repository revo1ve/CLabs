#include "Maze.h"
#include "MTreeNode.h"
#include "Direction.h"

void buildFullMaze(Maze& iMaze, MTreeNode& tree);

int* generateEntryPoint(int n, int m);

vector<Direction>* getPossibleDirections(Maze& maze, int i, int j);

bool cellVisited(Maze& maze, int i, int j);

int main()
{
	int n = 0;
	int m = 0;
	cout << "Input labyrinth sizes: ";
	cin >> n >> m;

	Maze* randomMaze = new Maze(n, m);
	auto entryPoint = generateEntryPoint(n, m);
	MTreeNode* tree = MTreeNode::beginTree(*entryPoint, *(entryPoint + 1));
	buildFullMaze(*randomMaze, *tree);
	randomMaze->printMaze();

	int maxWeight = 0;
	int weightSum = 0;
	int* weights = new int[n * m];

	for (int i = 0; i < n * m; i++)
		weights[i] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			auto foundNode = tree->searchNode(*tree, i, j);
			auto foundNodeWeight = foundNode->distance();
			weights[i * m + j] = foundNodeWeight;
			maxWeight = foundNodeWeight > maxWeight ? foundNodeWeight : maxWeight;
			weightSum += foundNodeWeight;
		}
	}

	cout << "Maze weights: " << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%4d", weights[i * m + j]);

		cout << "\n";
	}

	cout << "Max weight: " << maxWeight << "\n" << "Weight average: " << (float)weightSum / (n * m);
}

void buildFullMaze(Maze& iMaze, MTreeNode& tree)
{
	MTreeNode* currentNode = &tree;
	
	while (currentNode != nullptr)
	{
		int i = currentNode->i();
		int j = currentNode->j();
		auto possibleDirections = getPossibleDirections(iMaze, i, j);

		if (!possibleDirections->empty())
		{
			Direction randomDirection = possibleDirections->at(rand() % possibleDirections->size());

			switch (randomDirection)
			{
			case Direction::Up:
				currentNode->addChild(i - 1, j);
				currentNode = currentNode->hasChild(i - 1, j);
				iMaze.makeConnection(i, j, i - 1, j);
				continue;
			case Direction::Right:
				currentNode->addChild(i, j + 1);
				currentNode = currentNode->hasChild(i, j + 1);
				iMaze.makeConnection(i, j, i, j + 1);
				continue;
			case Direction::Down:
				currentNode->addChild(i + 1, j);
				currentNode = currentNode->hasChild(i + 1, j);
				iMaze.makeConnection(i, j, i + 1, j);
				continue;
			case Direction::Left:
				currentNode->addChild(i, j - 1);
				currentNode = currentNode->hasChild(i, j - 1);
				iMaze.makeConnection(i, j, i, j - 1);
				continue;
			default:
				break;
			}
		}
		else currentNode = (MTreeNode*)currentNode->parent();
	}
}

int* generateEntryPoint(int n, int m)
{
	srand((unsigned)time(0));
	Direction sides[4] = { Direction::Up, Direction::Right, Direction::Down, Direction::Left };
	Direction randomSide = sides[rand() % 4];

	switch (randomSide)
	{
	case Direction::Up:
		return new int[] { 0, rand() % m };
	case Direction::Right:
		return new int[] { rand() % n, m - 1 };
	case Direction::Down:
		return new int[] { n - 1, rand() % m };
	case Direction::Left:
		return new int[] { rand() % n, 0 };
	default:
		return new int[] { 0, 0 };
	}
}

vector<Direction>* getPossibleDirections(Maze& maze, int i, int j)
{
	auto possibleDirections = new vector<Direction>();

	if (!cellVisited(maze, i - 1, j))
		possibleDirections->push_back(Direction::Up);
	if (!cellVisited(maze, i + 1, j))
		possibleDirections->push_back(Direction::Down);
	if (!cellVisited(maze, i, j + 1))
		possibleDirections->push_back(Direction::Right);
	if (!cellVisited(maze, i, j - 1))
		possibleDirections->push_back(Direction::Left);

	return possibleDirections;
}

bool cellVisited(Maze& maze, int i, int j)
{
	return !(maze.cellInMaze(i, j)) || maze.hasConnection(i, j, i - 1, j) || maze.hasConnection(i, j, i + 1, j)
		|| maze.hasConnection(i, j, i, j - 1) || maze.hasConnection(i, j, i, j + 1);
}
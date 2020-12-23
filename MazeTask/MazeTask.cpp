#include "Maze.h"
#include "MTreeNode.h"

void buildFullMaze(Maze& iMaze, MTreeNode& tree)
{
	MTreeNode* currentNode = &tree;

	while (currentNode != nullptr)
	{
		int i = currentNode->i();
		int j = currentNode->j();
		auto possibleDirections = new vector<int>();

		if (!(!iMaze.cellInMaze(i - 1, j)
			|| iMaze.hasConnection(i - 1, j, i - 2, j) || iMaze.hasConnection(i - 1, j, i, j)
			|| iMaze.hasConnection(i - 1, j, i - 1, j - 1) || iMaze.hasConnection(i - 1, j, i - 1, j + 1)))
			possibleDirections->push_back(0);
		if (!(!iMaze.cellInMaze(i, j + 1)
			|| iMaze.hasConnection(i, j + 1, i - 1, j + 1) || iMaze.hasConnection(i, j + 1, i + 1, j + 1)
			|| iMaze.hasConnection(i, j + 1, i, j) || iMaze.hasConnection(i, j + 1, i, j + 2)))
			possibleDirections->push_back(1);
		if (!(!iMaze.cellInMaze(i + 1, j)
			|| iMaze.hasConnection(i + 1, j, i, j) || iMaze.hasConnection(i + 1, j, i + 2, j)
			|| iMaze.hasConnection(i + 1, j, i + 1, j - 1) || iMaze.hasConnection(i + 1, j, i + 1, j + 1)))
			possibleDirections->push_back(2);
		if (!(!iMaze.cellInMaze(i, j - 1)
			|| iMaze.hasConnection(i, j - 1, i - 1, j - 1) || iMaze.hasConnection(i, j - 1, i + 1, j - 1)
			|| iMaze.hasConnection(i, j - 1, i, j - 2) || iMaze.hasConnection(i, j - 1, i, j)))
			possibleDirections->push_back(3);

		if (!possibleDirections->empty())
		{
			int randomDirection = possibleDirections->at(rand() % possibleDirections->size());

			switch (randomDirection)
			{
			case 0:
				currentNode->addChild(i - 1, j);
				currentNode = currentNode->hasChild(i - 1, j);
				iMaze.makeConnection(i, j, i - 1, j);
				continue;
			case 1:
				currentNode->addChild(i, j + 1);
				currentNode = currentNode->hasChild(i, j + 1);
				iMaze.makeConnection(i, j, i, j + 1);
				continue;
			case 2:
				currentNode->addChild(i + 1, j);
				currentNode = currentNode->hasChild(i + 1, j);
				iMaze.makeConnection(i, j, i + 1, j);
				continue;
			case 3:
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

int main()
{
	int n = 0;
	int m = 0;
	cout << "Input labyrinth sizes: ";
	cin >> n >> m;

	Maze* randomMaze = new Maze(n, m);
	int* entryPoint = new int[] { 0, 0 };

	srand((unsigned)time(0));
	int sides[4] = { 0, 1, 2, 3 };
	int randomSide = sides[rand() % 4];

	switch (randomSide)
	{
	case 0:
		entryPoint = new int[] { 0, rand() % m };
		break;
	case 1:
		entryPoint = new int[] { rand() % n, m - 1 };
		break;
	case 2:
		entryPoint = new int[] { n - 1, rand() % m };
		break;
	case 3:
		entryPoint = new int[] { rand() % n, 0 };
		break;
	default:
		entryPoint = new int[] { 0, 0 };
		break;
	}

	MTreeNode* tree = MTreeNode::beginTree(entryPoint[0], entryPoint[1]);
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

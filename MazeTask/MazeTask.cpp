#include "Maze.h"
#include "MTreeNode.h"

int main()
{
	Maze* ladderMaze = new Maze(5, 5);

	for (int i = 0; i < 5; i++)
	{
		ladderMaze->makeConnection(i, i, i - 1, i);
		for (int j = 1; j < 5; j++)
		{
			ladderMaze->makeConnection(i + j - 1, i, i + j, i);
			ladderMaze->makeConnection(i, i + j - 1, i, i + j);
		}
	}

	ladderMaze->printMaze();

	MTreeNode* tree = MTreeNode::beginTree(0, 0);
	MTreeNode* currentNode = tree;
	int* mazeWeights = new int[25];

	for (int i = 0; i < 25; i++)
		mazeWeights[i] = 0;

	while (currentNode != nullptr)
	{
		int i = currentNode->i();
		int j = currentNode->j();
		mazeWeights[i * 5 + j] = currentNode->distance();

		auto downsideNode = currentNode->hasChild(i + 1, j);
		if (downsideNode == nullptr && ladderMaze->hasConnection(i, j, i + 1, j))
		{
			currentNode->addChild(i + 1, j);
			currentNode = currentNode->hasChild(i + 1, j);
			continue;
		}

		auto rightsideNode = currentNode->hasChild(i, j + 1);
		if (rightsideNode == nullptr && ladderMaze->hasConnection(i, j, i, j + 1))
		{
			currentNode->addChild(i, j + 1);
			currentNode = currentNode->hasChild(i, j + 1);
			continue;
		}

		currentNode = (MTreeNode*)currentNode->parent();
	}

	cout << endl << "Maze weights: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << mazeWeights[i * 5 + j] << " ";

		cout << endl;
	}
}

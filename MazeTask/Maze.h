#pragma once
#include <xmemory>
#include <iostream>

using namespace std;

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

class Maze
{
private:
	MCell* m_field;
	int m_n;
	int m_m;
public:
	Maze(int n, int m);
	~Maze();
	void printMaze();
	bool cellInMaze(int i, int j);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
};

Maze* createLadderMaze(int n, int j);

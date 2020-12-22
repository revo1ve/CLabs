#pragma once
#include "MCell.h"
#include <xmemory>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Maze
{
public:
	Maze(int n, int m) : m_n(n), m_m(m) { m_field = new MCell[n * m]; }
	~Maze() { free(m_field); }
	int n() const { return m_n; };
	int m() const { return m_m; };
	void printMaze();
	bool cellInMaze(int i, int j) { return i >= 0 && i < m_n&& j >= 0 && j < m_m; }
	const MCell& cell(int i, int j) const { return m_field[i * m_m + j]; }
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
private:
	MCell* m_field;
	int m_n;
	int m_m;
};

#pragma once
#include <vector>

using namespace std;

class MTreeNode
{
public:
	int i() const { return this->m_i; }
	int j() const { return this->m_j; }
	int distance() const { return this->m_distance; }
	int childCount() const { return m_children.size(); }
	bool addChild(int i, int j);
	const MTreeNode* child(int i);
	const MTreeNode* parent() const { return m_parent; }
	MTreeNode* hasChild(int i, int j);
	static MTreeNode* beginTree(int i, int j);
	MTreeNode* searchNode(const MTreeNode& tree, const int i, const int j);
private:
	int m_i, m_j;
	int m_distance;
	MTreeNode* m_parent;
	vector<MTreeNode*> m_children;
	MTreeNode(MTreeNode* parent);
};

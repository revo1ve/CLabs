#include "MTreeNode.h"

MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_i = 0;
	m_j = 0; 
	m_parent = parent;
	m_distance = parent == nullptr ? 0 : parent->distance() + 1;
	m_children = vector<MTreeNode*>();
};

bool MTreeNode::addChild(int i, int j) 
{ 
	auto child = new MTreeNode(this);
	child->m_i = i;
	child->m_j = j;
	m_children.push_back(child);
	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (auto node : this->m_children)
		if (node->m_i == i && node->m_j == j)
			return node;

	return nullptr;
}

const MTreeNode* MTreeNode::child(int i)
{
	for (int j = 0; j < m_j; j++)
	{
		auto child = hasChild(j, i);
		if (child != nullptr) return child;
	}

	return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto tree = new MTreeNode(nullptr);
	tree->m_i = i;
	tree->m_j = j;
	return tree;
}

MTreeNode* MTreeNode::searchNode(const MTreeNode& tree, const int i, const int j)
{
	if (tree.m_i == i && tree.m_j == j) return &(MTreeNode)tree;

	if (tree.childCount() > 0)
	{
		for (auto node : tree.m_children)
			if (node->m_i == i && node->m_j == j)
				return node;

		for (auto node : tree.m_children)
		{
			auto foundNode = searchNode(*node, i, j);
			if (foundNode != nullptr) return foundNode;
		}
	}

	return nullptr;
}

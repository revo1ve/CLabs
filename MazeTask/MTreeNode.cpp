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

int MTreeNode::i() const { return this->m_i; }

int MTreeNode::j() const { return this->m_j; }

int MTreeNode::distance() const { return this->m_distance; }

const MTreeNode* MTreeNode::parent() const { return m_parent; }

int MTreeNode::childCount() const { return m_children.size(); }

MTreeNode* MTreeNode::beginTree(int i, int j) { return new MTreeNode(nullptr); }

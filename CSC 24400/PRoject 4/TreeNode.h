// Dillon Geary 26 November
#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

#include <iostream>
#include <string>
#include "Candy.h"
class TreeNode
{
private:
	Candy _element;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;
public:
	TreeNode(const Candy &data) :
		_element(data), _left(NULL), _right(NULL), _parent(NULL) {}


	const Candy& value() const { return _element; }
	const TreeNode* left() const { return _left; }
	const TreeNode* right() const { return _right; }
	const TreeNode* parent() const { return _parent; }

	Candy& value() { return _element; }
	TreeNode*& left() { return _left; }
	TreeNode*& right() { return _right; }
	TreeNode*& parent() { return _parent; }

	bool isLeaf() const;
	unsigned int depth() const;
};

#endif


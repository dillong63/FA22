// Dillon Geary 26 November
#include "CandySet.h"

using namespace std;
TreeNode* addHelper(TreeNode* subTree, const TreeNode* newNode);
TreeNode* findHelper(const Candy& c, const TreeNode* ptr);
void printHelper(const TreeNode* subtree, ostream& os);
TreeNode* copyHelper(TreeNode* ori);
bool setSame(const TreeNode* fRoot, const TreeNode* sRoot);
bool found(const TreeNode* fRoot, const TreeNode* sRoot);

bool val;

CandySet::CandySet()//default constructor
{
	_root = NULL;
	_size = 0;
}

CandySet::CandySet(istream& is) //constructor reading in from the text file
{
	_size = 0;
	_root = NULL;
	Candy candy;
	is >> candy;
	TreeNode* newNode = new TreeNode(candy);
	_root = newNode;
	_size++;
	while (is)
	{
		is >> candy;
		*this += candy; //uses += to add to set
	}
}

CandySet::CandySet(const CandySet& set)//copy constructor
{
	_size = set._size;
	_root = copyHelper(set._root); //copyHelper returns root

}

TreeNode* copyHelper(TreeNode* ori)
{
	if (!ori) //base case for recursion
		return NULL; 
	
	TreeNode* newNode = new TreeNode(ori->value());//new Node for each value in other tree
	newNode->left() = copyHelper(ori->left());// traverses all left elements
	if (newNode->left())
		newNode->left()->parent() = newNode;//sets the parent node to all left elements
	newNode->right() = copyHelper(ori->right()); // does same as above for right
	if (newNode->right())
		newNode->right()->parent() = newNode;
	return newNode; //return the root after recursion finishes
}



TreeNode* addHelper(TreeNode* subTree, const TreeNode* newNode)
{
	if (!newNode)
		return (TreeNode*)subTree;
	if (!subTree)
		return(TreeNode*)newNode;
	if (newNode->value().name() < subTree->value().name())//if its smaller than subtree
	{
		subTree->left() = addHelper(subTree->left(), newNode); // move to the left
		subTree->left()->parent() = subTree; //set parent
	}
	else//if bigger than subtree value add it to the right
	{
	subTree->right() = addHelper(subTree->right(), newNode); //move right
	subTree->right()->parent() = subTree;
	}

	return subTree;
}

CandySet
const CandySet::operator+=(const Candy& newCandy) //adds a new candy to the set
{
	if (find(newCandy.name()) != NULL)//checks to see if it is already in the set
		return *this;
	TreeNode* newNode = new TreeNode(newCandy);
	if (_root == NULL) // if there is no root at this value as the node
	{
		_root = newNode;
		_size++;
		return *this;
	} 
	addHelper(_root, newNode); //use call helper to add value
	_size++; //increase size count
	return *this;
}

CandySet
const CandySet::operator-=(const Candy& remove)//removes the candy
{
	TreeNode* del = findL(remove.name());
	if (!del)
		return *this;

	if (del->isLeaf())
	{
		if (del == _root) //delete the root
		{
			_root = NULL;
			_size = 0;
			return *this;
		}

		TreeNode* parent = del->parent();
		if (parent->left() == del) //if it is the left node delete it
			parent->left() = NULL; 
		else//if right node delete it
			parent->right() = NULL;

		_size--;
		del->parent() = del->left() = del->right() = NULL;
		return *this;
	}
	else if ((del->left() && !del->right()) || (!del->left() && del->right()))
	{
		if (del == _root)
		{
			if (del->left()) // if there is a left node set it as the new root
			{
				_root = del->left();
			}
			else //else make the right node the root
			{
				_root = del->right();
			}
			_root->parent() = NULL;
			_size--;
			return *this;
		}

		TreeNode* move;
		if (del->left()) //left subtree is our child
			move = del->left();
		else //right subtree is out child
			move = del->right();

		TreeNode* parent = del->parent();
		if (parent->left() == del) //left node of parent is to be deleted
			parent->left() = move; //move the left tree up and remove the middle node
		else // same as above except for the right node case
			parent->right() = move;

		move->parent() = parent;
		_size--;
		return *this;
	}
	else //there are 2 childern
	{
		TreeNode* largestLeft;
		largestLeft = del->left(); //move one left
		while (largestLeft->right() != NULL)//find largest value to right of it
		{
			largestLeft = largestLeft->right();
			}
		Candy elementKeep = largestLeft->value();//store element
		*this -= elementKeep; //remove it from tree
		del->value() = elementKeep;// place it where the value is which is being deleted
		return *this;
	}
}




CandySet
const CandySet::operator-=(string remove) //remove function but with a string
{
	Candy candy(remove, 0); //create a candy to use -= above
	*this -= candy;
	return *this;
}


Candy*
CandySet::find(const std::string& scandy)
{
	return(Candy*)(findL(scandy));//uses listnode* I coded earlier to return candy*
}

TreeNode*
CandySet::findL(const string& scandy) const 
{
	Candy candy(scandy, 0);
	return findHelper(candy,_root);
}

TreeNode* findHelper(const Candy &c, const TreeNode* ptr)
{
	if (!ptr) //base case
		return NULL;
	if (ptr->value() == c) 
		return (TreeNode*)ptr; //return ptr if found

	if (c > ptr->value())
		return findHelper(c, ptr->right()); //if value looking for is smaller than node move to left
	else 
		return findHelper(c, ptr->left()); // if value is more look for it to the right;
}
bool
found(const TreeNode* fRoot, const TreeNode* sRoot)
{
	if(findHelper(fRoot->value(),sRoot)==NULL)//if element is not found
		return false;
	else
		return true;
}
bool setSame(const TreeNode* fRoot, const TreeNode* sRoot)
{
	if (!fRoot) //base case
	{
		return false;
	}
	if (!found(fRoot, sRoot)) //calls function to find element, needed to be done outside my recursive function as it did not work when it was inside it
		val = false;
	setSame(fRoot->left(), sRoot); //traverses elements
	setSame(fRoot->right(), sRoot); //traverses elements
	
	return val;
}

bool
CandySet::operator==(const CandySet& secondSet)const
{
	val = true; //sets global var to true as assumes they are equal
	if (_size != secondSet._size)//sizes are not equal they are not equal
		return false;
	if (setSame(_root, secondSet._root) == 0) //calls function if it returns false not equal
		return false;
	else
		return true;
}

bool
CandySet::operator!=(const CandySet& secondSet)const
{
	if (*this == secondSet)//calls == returns the opposite
		return false;
	else
		return true;
}

int
CandySet::size()const
{
	return _size; //return size which I have updated throughout class
}



CandySet
const CandySet::operator=(const CandySet& set)
{
	_size = set._size; //same size
	_root=copyHelper(set._root);
	return *this;
}

void
CandySet::clear()
{
	_root = NULL;
	_size = 0;
}


ostream& operator<<(std::ostream& os, const CandySet& c) //prints the elements
{
	printHelper(c._root, os);
	return os;
}

void printHelper(const TreeNode* subtree, ostream& os)//recursive call to print in order
{
	if (!subtree)// base case
		return;

	printHelper(subtree->left(), os); 
	os << subtree->value() << endl;
	printHelper(subtree->right(), os);
}

istream& operator>> (std::istream& is, CandySet& c)// reads in new candyset.
{
	c._root = NULL;
	Candy candy;
	is >> candy;
	TreeNode* newNode = new TreeNode(candy);
	c._root = newNode;
	while (is)
	{
		is >> candy;
		c += candy;
	}
	return is;
}

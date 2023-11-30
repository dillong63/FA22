//Dillon Geary 19 November

#include "CandySet.hpp"

using namespace std;

CandySet::CandySet()//default constructor
{
	_head = NULL;
	_tail = NULL;
}
	
CandySet::CandySet(istream &is) //constructor reading in from the text file
{
	_head = NULL;
	_tail = NULL;
	Candy candy;
	is>> candy ;
	while(is)
	{
		*this += candy;
		is>> candy ;
	}
}

CandySet::CandySet(const CandySet &set)//copy constructor
{
	ListNode *curr;
	curr=set._head;
	_tail=NULL;
	while(curr!=NULL)
	{
		(*this).addTail(curr->element());
		curr = curr->next();	
	}
}

CandySet
const CandySet::operator+=(const Candy &newCandy) //adds a new candy to the set
{
	if(find(newCandy.name())!=NULL)//checks to see if it is already in the set
		return *this;
	ListNode *newNode = new ListNode(newCandy); //rest of code adds the new node at the head
	newNode -> next()=_head;
	_head = newNode;
	if (_head->next() == NULL) 
		_tail = newNode;	
	return *this;
}

CandySet
const CandySet::operator-=(const Candy &remove)//removes the candy
{
	if(findL(remove.name())==NULL)//if the candy is not in the set return
		return *this;
	ListNode *node=findL(remove.name());
	ListNode *prev = findPrev(node, _head);
	if (node!=_head && node!=_tail)	//if the tail is not the head or tail remove it by pointing the previos to its next
	{
		prev->next() = node -> next();
	}
	else if (node == _head) //if the node is the head just change the head
	{
		_head= _head->next(); 
		if (_head ==NULL) 
			_tail = NULL;
	}
	else //if the node is tail just change the tail to the prev
	{
		prev->next() = node -> next(); 
		_tail = prev;
	}
 	return *this;
}

CandySet
const CandySet::operator-=(string remove) //remove function but with a string
{
	Candy candy(remove,0); //create a candy to use -= above
	*this-=candy;
	return *this;
}


Candy* 
CandySet::find(const std::string &scandy)
{
	return(Candy*)(findL(scandy));//uses listnode* I coded earlier to return candy*
}

ListNode* 
CandySet::findL(const string &scandy) const //find the element by traversing the candyset
{
	Candy candy(scandy,0);
	ListNode *curr;
	curr = _head;
	while(curr)
	{
		if(curr->element()==candy)
			return curr;
		curr = curr->next();	
	}	
 	return NULL;
}

bool
CandySet::operator==(const CandySet &secondSet)const
{
	ListNode *curr;
	ListNode *scurr;
	curr=_head;
	scurr=secondSet._head;
	while(curr&&scurr) //while both are not null, run the loop.
	{
		if((findL((scurr->element().name())))==NULL)//if an element differs return null
			return false;
		curr=curr->next();
		scurr=scurr->next();
	}
	if(scurr!=NULL)//if it exits the loop and is not null means that the onemset is shorter than the others
		return false;
	if(curr!=NULL) //inverse of above
		return false;	
	return true;
}
	
bool 
CandySet::operator!=(const CandySet &secondSet)const
{
	if(*this==secondSet)//calls == returns the opposite
		return false;
	else 
		return true;
}

int 
CandySet::size()const 
{
	int count=0;
	ListNode *curr;
	curr = _head;
	while (curr!=NULL) //counts amount of nodes as traverses the array
	{
		curr = curr -> next();
		count++;
	}	
		return count;
}



CandySet
const CandySet::operator=(const CandySet &set)
{
	ListNode *curr;
	curr=set._head;
	_tail=NULL;
	while(curr!=NULL)
	{
		(*this).addTail(curr->element()); //adds the second set elment to the first set
		curr = curr->next();	
	}
	return *this;
}

void
CandySet::clear()
{
	_head=NULL;
	_tail=NULL;
}

ostream& operator<<(std::ostream &os, const CandySet &c) //prints the elements
{
	ListNode *curr;
	curr = c._head;
	while (curr!=NULL) 
	{
		os << curr->element() << endl;
		curr = curr -> next();
	}
	return os;
		

}

istream& operator>> (std::istream &is, CandySet &c)// reads in new candyset.
{
	c._head=NULL;
	c._tail=NULL;
	Candy candy;
	is>> candy ;
	while(is)
	{
		c += candy;
		is>> candy ;
	}
	return is;
}

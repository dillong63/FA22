#ifndef _LIST_NODE_HPP_
#define _LIST_NODE_HPP_

#include <iostream>
#include "Candy.hpp"
class ListNode
{
private:
	Candy _element;
	ListNode *_next;
public:
	ListNode(Candy c) : _element(c),  _next(NULL) {}
	
	Candy element() const {return _element;} 
	Candy & element() {return _element;}      
	
	ListNode* next() const {return _next;}    
	ListNode* & next() {return _next;}
	
	friend std::ostream& operator << (std::ostream &os, const ListNode &ln); 
};

#endif

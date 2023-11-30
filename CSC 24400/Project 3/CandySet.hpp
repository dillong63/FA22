// Dillon Geary 19 Novemeber

#ifndef _CANDYSET_HPP_
#define _CANDYSET_HPP_

#include <fstream>
#include <string>
#include "Candy.hpp"
#include "ListNode.hpp"

class CandySet
{
private:
	ListNode* _parent;
	ListNode *_left;
    ListNode *_right;
public:
	CandySet(); //default constructor
	CandySet(std::istream &is); //constructor reading in from the text file
	CandySet(const CandySet &set);//copy constructor
	const CandySet operator+=(const Candy &newCandy);
	const CandySet operator-=(const Candy &remove);
	const CandySet operator-=(std::string remove);
	ListNode* findPrev(ListNode *findMe, ListNode *fromHead);
	Candy* find(const std::string &scandy);
	ListNode* findL(const std::string &scandy)const;
	void addTail(const Candy &c);
	bool operator==(const CandySet &secondSet)const;
	bool operator!=(const CandySet &secondSet)const;
	int size()const;
	const CandySet operator=(const CandySet &set);
	void clear();
	
	friend std::ostream& operator<<(std::ostream &os, const CandySet &c);
	friend std::istream& operator>> (std::istream &is, CandySet &c);
};

#endif
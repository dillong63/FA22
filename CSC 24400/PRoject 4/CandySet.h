#ifndef _CANDYSET_H_
#define _CANDYSET_H_

#include <fstream>
#include <string>
#include "Candy.h"
// Dillon Geary 26 November
#include "TreeNode.h"

class CandySet
{
private:
	TreeNode * _root;
	int _size;
public:
	CandySet(); //default constructor
	CandySet(std::istream& is); //constructor reading in from the text file
	CandySet(const CandySet& set);//copy constructor
	const CandySet operator+=(const Candy& newCandy);
	const CandySet operator-=(const Candy& remove);
	const CandySet operator-=(std::string remove);
	Candy* find(const std::string& scandy);
	TreeNode* findL(const std::string& scandy)const;
	bool operator==(const CandySet& secondSet)const;
	bool operator!=(const CandySet& secondSet)const;
	int size()const;
	const CandySet operator=(const CandySet& set);
	void clear();

	friend std::ostream& operator<<(std::ostream& os, const CandySet& c);
	friend std::istream& operator>> (std::istream& is, CandySet& c);
};

#endif

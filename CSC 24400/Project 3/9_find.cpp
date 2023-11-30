/****************************************************************
 ** FILE: 9_find.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor along with
 **     find method and +=,<< operators
 ****************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  CandySet bag;

  Candy c1("first", 1);
  Candy c2("second", 2);
  Candy c3("third", 3);
  Candy c4("fourth", 4);

  bag += c1;
  bag += c2;
  bag += c3;
  bag += c4;

  if (bag.find("third") != NULL)
    cout << "Correctly found \"third\" ." << endl;
  else
    cout << "INCORRECT: Could not find \"third\" ." << endl;

  Candy *ptrToCandy = bag.find("third");

  // utilize Candy's += operator. 
  ptrToCandy->operator+=(3);
  (*ptrToCandy)+=4;
  
  cout << "In following 4 candies, \"third\" sould have rating of 3.5"
       << " with 2 ratings:" << endl << bag;

  return 0;
}

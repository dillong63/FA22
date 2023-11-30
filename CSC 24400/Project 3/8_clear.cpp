/****************************************************************
 ** FILE: 8_clear.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor along with
 **     clear method and +=,<< operators
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

  cout << "The following should display 4 candies:" << endl << bag
       << "Size should be 4, it is: " << bag.size() << endl;

  bag.clear();

  cout << "The following should display 0 candies:" << endl << bag
       << "Size should be 0, it is: " << bag.size() << endl;
  
  return 0;
}

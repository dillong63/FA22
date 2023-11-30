/*************************************************************
 ** FILE: 1_VeryBasics.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor and associated calls
 **            to size and spaceLeft
 *************************************************************/

#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  CandySet empty; // default constructor

  cout << "CandySet's size should be 0 ... it is actually "
       << empty.size() << endl;
  

    
  return 0;
}

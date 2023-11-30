/****************************************************************
 ** FILE: 11_IO2.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022  
 ** PURPOSE: tests default constructor along with
 **      << and >> operators
 ****************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  CandySet bag1;

  ifstream ifile1("input1.txt");
  if (!ifile1)
    {
      cout << "Could not open \"input1.txt\". Is it in your working directory?"
           << endl;
      return 1;
    }

  ifile1 >> bag1;

  ifstream ifile2("input2.txt");
  if (!ifile2)
    {
      cout << "Could not open \"input2.txt\". Is it in your working directory?"
           << endl;
      return 1;
    }
  
  ifile2 >> bag1;

  cout << "The following should have 8 (*not* 12) Candy objects in it :"
       << endl << bag1;
  cout << "Size should be 8. It is: " << bag1.size() << endl;
  
  return 0;
}

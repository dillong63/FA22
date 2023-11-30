/*************************************************************
 ** FILE: 3_IO.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests ifstream constructor and <<,>> operators
 **            to size and spaceLeft
 *************************************************************/

#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile1("input1.txt");
  if (!ifile1)
    {
      cout << "Could not open \"input1.txt\". Is it in your working directory?"
	   << endl;
      return 1;
    }

  CandySet someCandy(ifile1);

  cout << "The following should have 4 candy bars in it "
       << "(see \"input1.txt\" for details)"
       << endl;
  cout << "=== begin input1.txt based ===" << endl;
  cout << someCandy;
  cout << "=== end input1.txt based ===" << endl;


  ifstream ifile2("input2.txt");
  if (!ifile2)
    {
      cout << "Could not open \"input2.txt\". Is it in your working directory?"
	   << endl;
      return 1;
    }

  CandySet otherCandy;

  ifile2 >> otherCandy;

  cout << "The following should have 8 candy bars in it "
       << "(see \"input2.txt\" for details)"
       << endl;
  cout << "=== begin input2.txt based ===" << endl;
  cout << otherCandy;
  cout << "=== end input2.txt based ===" << endl;


  
  return 0;

}

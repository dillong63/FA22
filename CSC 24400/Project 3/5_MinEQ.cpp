/****************************************************************
 ** FILE: 5_MinusEQ.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor += <<,>> and -= operators
 ****************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile2("input2.txt");
  if (!ifile2)
    {
      cout << "Could not open \"input2.txt\". Is it in your working directory?"
           << endl;
      return 1;
    }

  CandySet testing(ifile2);
  cout << "The following should have 8 candy bars in it:" << endl
       << testing;
    
  cout << "The set's size should be 8, it is: " << testing.size() << endl;
  
  Candy removeMe("AlmondJoy", 1);

  testing-=removeMe;

  cout << "The following should have 7 candy bars in it:" << endl
       << testing;
    
  cout << "The set's size should be 7, it is: " << testing.size() << endl;

  Candy first("Crunch", 1);

  testing-=first;

  cout << "The following should have 6 candy bars in it:" << endl
       << testing;
    
  cout << "The set's size should be 6, it is: " << testing.size() << endl;

  Candy last("OhHenry!", 1);

  testing-=last;

  cout << "The following should have 5 candy bars in it:" << endl
       << testing;
    
  cout << "The set's size should be 5, it is: " << testing.size() << endl;

  testing -=  "Goobers";
  testing -= "MilkyWay";

  cout << "The following should have 3 candy bars in it:" << endl
       << testing;
    
  cout << "The set's size should be 3, it is: " << testing.size() << endl;

  Candy bad("notThere", 100);
  testing -= bad;
  cout << "The set's size should still be 3, it is: " << testing.size() << endl;

  testing -= "MeanTrick";
  cout << "The set's size should still be 3, it is: " << testing.size() << endl;

  CandySet empty;
  empty -= "Raisinets";
  cout << "Removing from an empty set should have size 0, it is: "
       << empty.size() << endl;
  
  return 0;
}

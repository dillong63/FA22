/****************************************************************
 ** FILE: 7_Assign.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor along with
 **     +=, -=, =, and << operators.
 ****************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  CandySet initSet;

  Candy c1("first", 1);
  Candy c2("second", 2);
  Candy c3("third", 3);
  Candy c4("fourth", 4);

  initSet += c1;
  initSet += c2;
  initSet += c3;
  initSet += c4;

  cout << "The following should display 4 candies:" << endl << initSet
       << "Size should be 4, it is: " << initSet.size() << endl;
  

  CandySet duplicate;

  duplicate = initSet;
  
  cout << "This duplicate should display 4 candies:" << endl << duplicate
       << "Size should be 4, it is: " << duplicate.size() << endl;

  initSet-=c2;

  cout << endl << "AFTER REMOVING FROM INITIAL SET" << endl
       << "The initial set should display 3 candies:" << endl << initSet
       << "initial set size should be 3, it is: " << initSet.size() << endl
       << "The duplicate should still display 4 candies:" << endl << duplicate
       << "Duplicate's size should be 4, it is: " << duplicate.size() << endl;

  duplicate-=c3;

  cout << endl << "AFTER REMOVING FROM COPY CONSTRUCTED SET" << endl
       << "The initial set should display 3 candies:" << endl << initSet
       << "initial set size should be 3, it is: " << initSet.size() << endl
       << "The duplicate should display 3 candies:" << endl << duplicate
       << "Duplicate's size should be 3, it is: " << duplicate.size() << endl;



  
  return 0;
}

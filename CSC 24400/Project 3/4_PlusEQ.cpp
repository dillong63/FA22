/*************************************************************
 ** FILE: 4_PlusEQ.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor and <<,+= operators
 *************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  Candy c1("sucker", 120),
    c2("Chocolate", 150),
    c3("Apple", 80),
    c4("Milkshake", 490),
    c5("FrostedFlakes",95),
    c6("Gobstopper", 199);

  CandySet bag;

  bag+=c1;
  cout << "===== Bag with 1 candy in it =======" << endl << bag << endl;
  
  bag+=c2;
  cout << "===== Bag with 2 candies in it =======" << endl << bag << endl;
  
  bag+=c3;
  cout << "===== Bag with 3 candies in it =======" << endl << bag << endl;
  
  bag+=c4;
  cout << "===== Bag with 4 candies in it =======" << endl << bag << endl;
  
  bag+=c5;
  cout << "===== Bag with 5 candies in it =======" << endl << bag << endl;

  bag+=c6;
  cout << "===== Bag with 6 candies in it =======" << endl << bag << endl;

  cout << "The set's size should be 6. You got: " << bag.size() << endl;

  Candy tricky("Apple", 80);

  bag+=tricky;
  cout << "===== Bag with attempted duplicate  =======" << endl << bag << endl;

  cout << "The set's size should still be 6. You got: " << bag.size() << endl;

  Candy mean("AppleOfMyEye", 1);
  cout << "===== Bag should now have 7 items in it====" << endl
       << (bag+=mean);

  cout << "The set's size should now be 7. You got: " << bag.size() << endl;
  
  return 0;
}

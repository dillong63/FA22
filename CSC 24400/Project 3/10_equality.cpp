/****************************************************************
 ** FILE: 10_equality.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: tests default constructor along with
 **      +=,<<,==, and != operators
 ****************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.h"
#include "CandySet.h"

using namespace std;

int main(int argc, char *argv[])
{
  CandySet bag1, bag2;

  Candy c1("first", 1);
  Candy c2("second", 2);
  Candy c3("third", 3);
  Candy c4("fourth", 4);

  bag1 += c1;
  bag1 += c2;
  bag1 += c3;
  bag1 += c4;

  bag2 += c3;
  bag2 += c1;
  bag2 += c4;

  cout << "1) ";
  if (bag1==bag2)
    cout << "INcorrect: The two bags should not be equal!" << endl;
  else
    cout << "CORRECT: The two bags are not equal!" << endl;

  cout << "2) ";
  if (bag2==bag1)
    cout << "INcorrect: The two bags should not be equal!" << endl;
  else
    cout << "CORRECT: The two bags are not equal!" << endl;

  cout << "3) ";
  if (bag1!=bag2)
    cout << "CORRECT: The two bags are not equal!" << endl;
  else
    cout << "INcorrect: The two bags should not be equal!" << endl;

  cout << "4) ";
  if (bag2!=bag1)
    cout << "CORRECT: The two bags are not equal!" << endl;
  else
    cout << "INcorrect: The two bags should not be equal!" << endl;

  bag2 += c2;
  
  cout << "5) ";
  if (bag1==bag2)
    cout << "CORRECT: The two bags are equal!" << endl;
  else
    cout << "INcorrect: The two bags should be equal!" << endl;

  cout << "6) ";
  if (bag2==bag1)
    cout << "CORRECT: The two bags are equal!" << endl;
  else
    cout << "INcorrect: The two bags should be equal!" << endl;


  cout << "7) ";
  if (bag1!=bag2)
    cout << "INcorrect: The two bags should be equal!" << endl;
  else
    cout << "CORRECT: The two bags are equal!" << endl;

  cout << "8) ";
  if (bag2!=bag1)
    cout << "INcorrect: The two bags should be equal!" << endl;
  else
    cout << "CORRECT: The two bags are equal!" << endl;
  
  return 0;
}

/****************************************************************
 ** FILE: 12_const.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: Kdoes not really execute anything useful. Instead
 **     tests you have methods preoperly using const.
 ****************************************************************/

#include <fstream>
#include <iostream>

#include "Candy.hpp"
#include "CandySet.hpp"

using namespace std;

void compileTest(const CandySet &tester)
{
  // if a line in this function does not compile, you have something
  // that is not properly declared to be const.
  // NOTE: warnings are OK. 
  tester.size();

  CandySet dummy(tester);

  if (tester == dummy)
    ;
  if (dummy == tester)
    ;

  if (tester != dummy)
    ;
  if (dummy != tester)
    ;

  dummy = tester;
}

int main(int argc, char *argv[])
{
  CandySet halloween;

  compileTest(halloween);
  
  return 0;
}

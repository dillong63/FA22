/****************************************************************
 ** FILE: Candy.cpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: Implementtaion for Candy class, as used in CSC24400
 **            in Fall 2022. 
 ****************************************************************/
#include "Candy.h"

using namespace std;

// default constructor. 
Candy::Candy()
{
  _name = ">>generic<<";
  _calories = 750;
  _ratingAvg=0;
  _numRatings=0;
}

// non-default constructor
Candy::Candy(const string &name, int calories)
{
  _name = name;
  _calories = calories;
  _ratingAvg=0;
  _numRatings=0;
}

// copy constructor
Candy::Candy(const Candy &other)
{
  _name = other._name;
  _calories = other._calories;
  _ratingAvg=0;
  _numRatings=0;
}

// add this candy to specified stream
ostream& Candy::print(ostream &os) const
{
  os << _name << "(" << _calories << ") "
     << _ratingAvg << "(" << _numRatings << ")"; 
  return os;
}

// pull the data for this candy from the specified stream. 
istream& Candy::read(std::istream &is)
{
  is >> _name >> _calories >> _ratingAvg >> _numRatings;
  return is;
}


// overloaded += with new rating. 
const Candy&
Candy::operator+=(unsigned int newRating)
{
  // checj that the rating is valid before proceeding
  if (newRating<=4 && newRating>=1)
    {
      // some math ... to calculate new average based on old average
      //    and old number of ratings and then include new rating
      double avgsum = _ratingAvg*_numRatings;
      avgsum += newRating;
      _numRatings++;
      _ratingAvg = avgsum/_numRatings;
    }
  else
    {
      cout << "Invalid rating provided: " << newRating << endl; 
    }
  return *this;
}

// overload = to assign this to another Candy object
const Candy&
Candy::operator=(const Candy &rhs)
{
  _name = rhs._name;
  _calories = rhs._calories;
  _ratingAvg = rhs._ratingAvg;
  _numRatings = rhs._numRatings;

  return *this;
}

// determination for == is made based on name only !!!
bool Candy::operator==(const Candy &other)const
{
  return _name == other._name;
}

// determination for != is made based on name only !!!
bool Candy::operator!=(const Candy &other)const
{
  return !operator==(other);
}

// determination for < is made based on name only !!!
bool Candy::operator<(const Candy &other)const
{
  return _name < other._name;
}

// determination for > is made based on name only !!!
bool Candy::operator>(const Candy &other)const
{
  return other < *this;
}

// use the above print method to help overload <<
ostream& operator<<(ostream &os, const Candy &c)
{
  return c.print(os);
}

// use the above read method to help overload >>
istream& operator>>(istream &is, Candy &c)
{
  return c.read(is);
}

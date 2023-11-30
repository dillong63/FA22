/*************************************************************
 ** FILE: Candy.hpp
 ** AUTHOR: S. Blythe
 ** DATE: 10/2022
 ** PURPOSE: Header file for Candy class, as used in CSC24400
 **            in Fall 2022. 
 *************************************************************/
#ifndef _CANDY_HPP_
#define _CANDY_HPP_

#include <iostream>
#include <string>

class Candy
{
private:
  std::string _name;         // name of the candy
  unsigned int _calories;    // number of calories for this candy
  double _ratingAvg;         // current average rating
  unsigned int _numRatings;  // the number of ratings made so far
public:
  // default constructors
  Candy();

  // non-default constructor
  //    name - the name of the Candy
  //    calories - number of calories in this Candy
  Candy(const std::string &name, int calories);

  // copy constructor
  //    other - the Candy object to copy into this
  Candy(const Candy &other);
  
  // accessor methods
  const std::string& name() const {return _name;}
  int calories() const {return _calories;}

  // overload += to provide a new rating.
  const Candy& operator+=(unsigned int newRating);

  // overload = to assign this to another Candy object
  const Candy& operator=(const Candy &rhs); 
  
  // overload some comaprison operators between Candy objects
  bool operator==(const Candy &other)const;
  bool operator!=(const Candy &other)const;
  bool operator<(const Candy &other)const;
  bool operator>(const Candy &other)const;

  // some methods for I/O inside 
  std::ostream& print(std::ostream &os) const;
  std::istream& read(std::istream &is);
};

// overload << output and >> input operators
std::ostream& operator<<(std::ostream &os, const Candy &c);
std::istream& operator>>(std::istream &is, Candy &c);


#endif

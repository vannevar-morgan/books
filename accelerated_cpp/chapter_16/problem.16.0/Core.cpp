//#include <string>
#include <istream>
//#include <vector>
#include <iostream>
//#include "Vec.hpp"
#include "Str.hpp"
#include "Core.hpp"
#include "grading.hpp"
#include "median.hpp"
#include "ops.hpp"


Str Core::name() const
{
  return n;
}

bool Core::isValid() const
{
  // added the isValid() function for problem 13.3, 
  // to check if a student object holds valid values for grading.
  return !homework.empty();
}

bool Core::isMissingWork() const
{
  /*
   * Problem 13.5
   * Checks if a student has missing work.
   *
   * When checking homework, only checks if the student did no
   * homework because there is no prescribed number of homeworks.
   * 
   * Technically a student could do only one homework and still 
   * evaluate as not missing homework.
   */
  if(isValid()){
    return false;
  }
  return true;
}

double Core::grade() const
{
  return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in)
{
  in >> n >> midterm >> final;
  return in;
}

std::istream& Core::read(std::istream& in)
{
  read_common(in);
  read_hw(in, homework);
  return in;
}


#include "Core.hpp"
#include "grading.hpp"
#include "median.hpp"
#include "ops.hpp"
#include <string>
#include <istream>
#include <vector>
#include <iostream>


std::string Core::name() const
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
  if(Core::isValid()){
    return false;
  }else{
    return true;
  }
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

std::string Core::letter_grade(double numeric_grade)
{
  /*
   * Problem 13.4
   * Maps a numeric grade to a letter grade.
   * Implements grading policy outlined in 10.3 / 177
   */
  static const double numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
  static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
  
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
  
  for(size_t i = 0; i < ngrades; ++i){
    if(numeric_grade >= numbers[i]){
      return letters[i];
    }
  }
  return "?\?\?";
}

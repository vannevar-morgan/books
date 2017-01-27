#include <istream>
//#include <string>
#include <cstddef>
#include "Student_info.hpp"
#include "Core.hpp"
#include "Grad.hpp"


/*
 * November 25, 2015
 * 
 * Implementation for Student_info.
 */

Student_info::Student_info(const Student_info& s): cp(0)
{
  /*
   * Copy constructor for Student_info class.
   */
  if(s.cp){
    cp = s.cp->clone();
  }
}


Student_info& Student_info::operator= (const Student_info& s)
{
  /*
   * Assignment operator for Student_info class.
   */
  if(&s != this){
    delete cp;
    if(s.cp){
      cp = s.cp->clone();
    }else{
      cp = 0;
    }
  }
  return *this;
}


std::istream& Student_info::read(std::istream& is)
{
  /*
   * Read data from an input stream to a Student_info object.
   * 
   * Format is assumed to be a character 'U' or 'G' denoting
   * Undergrad student or Grad student, followed by data
   * appropriate for the student type.
   *
   * cp points to a Core or Grad for the respective entry type.
   */
  delete cp;

  char ch = ' ';
  is >> ch;
  
  if(ch == 'U'){
    cp = new Core(is);
  }else if(ch == 'G'){
    cp = new Grad(is);
  }

  return is;
}


Str Student_info::letter_grade(double numeric_grade)
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

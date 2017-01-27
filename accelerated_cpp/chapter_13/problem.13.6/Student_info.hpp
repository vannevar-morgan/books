#ifndef guard_student_info
#define guard_student_info

#include "Core.hpp"
#include <istream>
#include <string>
#include <stdexcept>
#include <iostream>


class Student_info
{
  /*
   * November 25, 2015
   * 
   * Student_info is a handle class for the Core and Grad classes.
   *
   * If a Student_info is not first initialized by reading into it with 
   * an istream before calling name() or grade() it will throw a 
   * std::runtime_error.
   */
public:
  Student_info(): cp(0) {}
  Student_info(std::istream& is): cp(0) { read(is); }
  Student_info(const Student_info&);
  Student_info& operator= (const Student_info&);
  ~Student_info() {}
  
  std::istream& read(std::istream& is);
  
  std::string name() const
  {
    /*
     * Returns a students name.
     */
    if(cp){
      return cp->name();
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }

  bool isValid() const
  {
    /*
     * Returns true if a Student_info object contains values valid for grading, false otherwise.
     *
     * Added the isValid() function for problem 13.3
     */
    if(cp){
      return cp->isValid();
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }
  
  bool isMissingWork() const
  {
    if(cp){
      return cp->isMissingWork();
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }
  
  double grade() const
  {
    /*
     * Returns a student's numeric grade.
     */
    if(cp){
      return cp->grade();
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }
  
  std::string letter_grade(double numeric_grade)
  {
    /*
     * Returns a student's letter grade.
     */
    if(cp){
      return cp->letter_grade(numeric_grade);
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }
  
  static bool compare(const Student_info& s1, const Student_info& s2)
  {
    /*
     * Compares two students by name.
     */
    return s1.name() < s2.name();
  }

  
  
private:
  Core* cp; // pointer to core, is dynamically bound to a core or derived class

};




#endif

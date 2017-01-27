#include "PassFailStudent.hpp"


bool PassFailStudent::isValid() const
{
  // Because a student taking the class for pass / fail credit
  // may or may not do the homework, we do not need to check if
  // the student did homework.  Therefore, the student is always
  // in a valid state.
  return true;
}


bool PassFailStudent::isMissingWork() const
{
  // Because a student taking the class for pass / fail credit
  // may or may not do the homework (and I'm not checking that 
  // all homework was done, no defined number of homeworks), 
  // the student never is missing work.  They either did or didn't
  // do homework but they aren't missing work.
  return false;
}


double PassFailStudent::grade() const
{
  if(Core::isMissingWork()){
    // Then the student did no homework, grade is the average of the midterm and final.
    return (midterm + final) / 2.0;
  }else{
    // The student did homework, grade with normal grading method.
    return Core::grade();
  }
}


std::string PassFailStudent::letter_grade(double numeric_grade)
{
  /*
   * Return a letter grade representing a numeric grade.
   * Pass / Fail students pass the class with a numeric
   * grade of 60 or better.
   */
  if(numeric_grade >= 60){
    return "P";
  }else{
    return "F";
  }
}

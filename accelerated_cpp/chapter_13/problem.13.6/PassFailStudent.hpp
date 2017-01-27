#ifndef guard_pass_fail
#define guard_pass_fail

#include "Core.hpp"
#include <istream>


class PassFailStudent: public Core
{
  /*
   * December 5, 2015
   * 
   * PassFailStudent is a class to represent pass / fail students.
   * It is assumed only undergrad students can take a pass / fail course (It does not contain a thesis member).
   * 
   */
  
public:
  PassFailStudent() {}
  PassFailStudent(std::istream& is) { Core::read(is); }
  
  bool isValid() const;
  bool isMissingWork() const;
  double grade() const;
  std::string letter_grade(double numeric_grade);
  
protected:
  PassFailStudent* clone() const { return new PassFailStudent(*this); }

};


#endif

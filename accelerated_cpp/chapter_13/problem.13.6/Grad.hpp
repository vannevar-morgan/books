#ifndef guard_grad_hpp
#define guard_grad_hpp

#include "Core.hpp"
#include <istream>

class Grad: public Core
{
  /*
   * November 25, 2015
   * 
   * Grad is a class to represent Graduate students.  It extends class Core
   * and adds a private thesis member.  The grading policy is changed to the
   * minimum of the normal grading policy and the thesis grade.
   */

public:
  Grad(): thesis(0) {}
  Grad(std::istream& is): thesis(0) { read(is); }

  bool isMissingWork() const
  {
    /*
     * Problem 13.5
     * Checks if a student has missing work.
     *
     * When checking homework, only checks if the student did no
     * homework because there is no defined number of homeworks.
     * 
     * Technically a student could do only one homework and still 
     * evaluate as not missing homework.
     */
    if(thesis && !Core::isMissingWork()){
      return false;
    }else{
      return true;
    }
  }

  double grade() const;
  std::istream& read(std::istream& is);

protected:
  Grad* clone() const { return new Grad(*this); }
  
private:
  double thesis;
  
};


#endif

#ifndef guard_grad_hpp
#define guard_grad_hpp

#include "Core.hpp"
#include <istream>

class Grad: public Core
{
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
     * homework because there is no prescribed number of homeworks.
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

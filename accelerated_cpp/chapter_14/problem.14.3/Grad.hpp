#ifndef guard_grad_hpp
#define guard_grad_hpp

#include "Core.hpp"
#include <istream>

class Grad: public Core
{
public:
  Grad(): thesis(0) {}
  Grad(std::istream& is): thesis(0) { read(is); }
  
  double grade() const;
  std::istream& read(std::istream& is);

  virtual void regrade(double new_final_grade, double new_thesis_grade = 0) { final = new_final_grade; thesis = new_thesis_grade; }


protected:
  Grad* clone() const { return new Grad(*this); }
  

private:
  double thesis;
  
};


#endif

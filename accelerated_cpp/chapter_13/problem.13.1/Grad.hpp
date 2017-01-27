#ifndef guard_grad_hpp
#define guard_grad_hpp

#include "Core.hpp"
#include <istream>
#include <iostream>

class Grad: public Core
{
public:
  Grad(): thesis(0)
  {
    std::cout << "Grad::Grad()" << std::endl;
  }
  
  Grad(std::istream& is): thesis(0)
  {
    std::cout << "Grad::Grad(std::istream& is)" << std::endl;
    read(is);
  }
  
  double grade() const;
  std::istream& read(std::istream& is);

protected:
  Grad* clone() const { return new Grad(*this); }
  
private:
  double thesis;
  
};


#endif

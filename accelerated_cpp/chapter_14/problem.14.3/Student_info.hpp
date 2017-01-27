#ifndef guard_student_info
#define guard_student_info

#include "Core.hpp"
#include "Ptr.hpp"
#include <istream>
#include <string>
#include <stdexcept>
#include <iostream>

class Student_info
{
public:
  Student_info() {}
  Student_info(std::istream& is) { read(is); }
  
  std::istream& read(std::istream& is);
  
  std::string name() const{
    /*
     * Returns a students name.
     */
    if(cp){
      return cp->name();
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }
  
  double grade() const
  {
    /*
     * Returns a students grade.
     */
    if(cp){
      return cp->grade();
    }else{
      throw std::runtime_error("uninitialized student");
    }
  }

  void regrade(double final, double thesis);
  
  static bool compare(const Student_info& s1, const Student_info& s2)
  {
    /*
     * Compares two students by name.
     */
    return s1.name() < s2.name();
  }
  
private:
  Ptr<Core> cp;

};




#endif

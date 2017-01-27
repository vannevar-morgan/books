#include "Student_info.hpp"
#include "Core.hpp"
#include "Grad.hpp"
#include <istream>

/*
 * Implementation for Student_info.
 */

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
  char ch = ' ';
  is >> ch;
  
  if(ch == 'U'){
    cp = new Core(is);
  }else{
    cp = new Grad(is);
  }

  return is;
}


void Student_info::regrade(double final, double thesis){
  cp.make_unique();
  if(cp){
    cp->regrade(final, thesis);
  }else{
    throw std::runtime_error("regrade of unknown student");
  }
}

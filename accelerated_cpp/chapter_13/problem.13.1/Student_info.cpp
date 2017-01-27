#include "Student_info.hpp"
#include "Core.hpp"
#include "Grad.hpp"
#include <istream>

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

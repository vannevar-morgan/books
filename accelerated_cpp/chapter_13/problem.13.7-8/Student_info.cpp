#include "Student_info.hpp"
#include "Core.hpp"
#include "Grad.hpp"
#include "PassFailStudent.hpp"
#include "AuditStudent.hpp"
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
   * Format is assumed to be a character 'U', 'G', 'P', or 'A' denoting
   * Undergrad student, Grad student, Pass/Fail student, or Audit student.
   * 
   * If a student is an Audit student then it is followed by a character,
   * 'U', 'G', or 'P' further specifying the student type.
   *
   * Student type information is followed by data appropriate for the student type.
   *
   * cp points to a Core or Grad for the respective entry type.
   */
  delete cp;

  char ch = ' ';
  is >> ch;
  
  if(ch == 'U'){
    cp = new Core(is);
  }else if(ch == 'P'){
    cp = new PassFailStudent(is);
  }else if(ch == 'G'){
    cp = new Grad(is);
  }else if(ch == 'A'){
    is >> ch;
    cp = new AuditStudent(ch, is);
  }

  return is;
}


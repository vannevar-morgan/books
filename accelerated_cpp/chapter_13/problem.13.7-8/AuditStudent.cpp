#include "AuditStudent.hpp"
#include <istream>
#include <string>
#include <stdexcept>


bool AuditStudent::isValid() const
{
  if(student_type == 'U'){
    return Core::isValid();
  }else if(student_type == 'G'){
    return Grad::isValid();
  }else if(student_type == 'P'){
    return PassFailStudent::isValid();
  }else{
    throw std::runtime_error("tried to call AuditStudent::isValid() on an audit student of unknown student type...");
  }
}


bool AuditStudent::isMissingWork() const
{
  if(student_type == 'U'){
    return Core::isMissingWork();
  }else if(student_type == 'G'){
    return Grad::isMissingWork();
  }else if(student_type == 'P'){
    return PassFailStudent::isMissingWork();
  }else{
    throw std::runtime_error("tried to call AuditStudent::isMissingWork() on an audit student of unknown student type...");
  }
}


std::istream& AuditStudent::read(std::istream& is)
{
  if(student_type == 'U'){
    return Core::read(is);
  }else if(student_type == 'G'){
    return Grad::read(is);
  }else if(student_type == 'P'){
    return PassFailStudent::read(is);
  }else{
    throw std::runtime_error("tried to call AuditStudent::read() on an audit student of unknown student type...");
  }
}


double AuditStudent::grade() const
{
  if(student_type == 'U'){
    return Core::grade();
  }else if(student_type == 'G'){
    return Grad::grade();
  }else if(student_type == 'P'){
    return PassFailStudent::grade();
  }else{
    throw std::runtime_error("tried to call AuditStudent::grade() on an audit student of unknown student type...");
  }
}


std::string AuditStudent::letter_grade(double numeric_grade)
{
  if(student_type == 'U'){
    return Core::letter_grade(numeric_grade) + " (Audit)";
  }else if(student_type == 'G'){
    return Grad::letter_grade(numeric_grade) + " (Audit)";
  }else if(student_type == 'P'){
    return PassFailStudent::letter_grade(numeric_grade) + " (Audit)";
  }else{
    throw std::runtime_error("tried to call AuditStudent::letter_grade() on an audit student of unknown student type...");
  }
}


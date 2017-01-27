#ifndef audit_student_hpp
#define audit_student_hpp

#include "Core.hpp"
#include "Grad.hpp"
#include "PassFailStudent.hpp"
#include <string>

class AuditStudent: public virtual Core, public virtual Grad, public virtual PassFailStudent
{
  /*
   * December 6, 2015
   * 
   * AuditStudent is a class to represent students auditing a course.
   * 
   * I can't imagine how auditing should be graded differently than a
   * normal student except that there should be a note that the student
   * audited the course.
   * 
   * Also undergrads, grads, and pass / fail students should be able 
   * to audit a course.
   */
  
public:
  AuditStudent(char s_type): student_type(s_type) {}
  AuditStudent(char s_type, std::istream& is): student_type(s_type) { read(is); }

  bool isValid() const;
  bool isMissingWork() const;

  std::istream& read(std::istream& is);
  double grade() const;
  std::string letter_grade(double numeric_grade);
  
  
  
protected:
  AuditStudent* clone() const { return new AuditStudent(*this); }

private:
  char student_type;
  
};


#endif

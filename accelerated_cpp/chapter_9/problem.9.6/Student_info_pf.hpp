#ifndef Student_info_pf_guard
#define Student_info_pf_guard

/*
 * Represents a students taking a class on a pass/fail basis
 */
#include <string>
#include <iostream>


class Student_info_pf
{
public:
  Student_info_pf(): midterm(0.0), final(0.0), final_grade('U'), name("") {}
  Student_info_pf(std::istream& is): final_grade('U') { read(is); }

  std::string getName() const { return name; }
  char getGrade() const {return final_grade; }
  std::istream& read(std::istream& input_stream);
  char grade();

private:
  double midterm;
  double final;
  char final_grade;
  std::string name;
  double grade(double midterm_exam, double final_exam) const;
  
};

bool compare_name(const Student_info_pf x, const Student_info_pf y);
bool passed_class(const Student_info_pf x);



#endif

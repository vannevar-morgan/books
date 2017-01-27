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
  Student_info_pf(): midterm(0.0), final(0.0), name("") {}
  Student_info_pf(std::istream& is) { read(is); }

  std::string getName() const { return name; }
  std::istream& read(std::istream& input_stream);
  char grade() const;

private:
  double midterm;
  double final;
  std::string name;
  double grade(double midterm_exam, double final_exam) const;
  
};

bool compare(const Student_info_pf x, const Student_info_pf y);



#endif

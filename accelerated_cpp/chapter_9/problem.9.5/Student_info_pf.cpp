#include "Student_info_pf.hpp"
#include <iostream>


std::istream& Student_info_pf::read(std::istream& is)
{
  std::cin >> name >> midterm >> final;
  return is;
}

double Student_info_pf::grade(double midterm_exam, double final_exam) const
{
  return (midterm_exam + final_exam) / 2;
}

char Student_info_pf::grade() const
{
  double final_grade = Student_info_pf::grade(midterm, final);
  if(final_grade > 60){
    return 'P';
  }else{
    return 'F';
  }
}

bool compare(const Student_info_pf x, const Student_info_pf y)
{
  return x.getName() < y.getName();
}

#include "grade.h"
#include "Student_info.h"
#include "median.h"  // for median()
#include <vector>  // for vector
#include <stdexcept>  // for exception classes


double grade(const Student_info& s)
{
  return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if(hw.size() == 0){
    throw std::domain_error("student has done no homework");
  }

  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

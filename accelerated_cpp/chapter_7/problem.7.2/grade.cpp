// source file for the grade-related functions

#include <stdexcept>
#include <vector>
#include <cassert>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
  if (hw.size() == 0)
    throw domain_error("student did no homework...");

  return grade(midterm, final, median(hw));
}

double grade(Student_info& s)
{
  s.final_grade = grade(s.midterm, s.final, s.homework);
  s.letter_grade = lookup_letter_grade(s);
  return s.final_grade;
}

char lookup_letter_grade(const Student_info& s){
  int numeric_grades[] = {90, 80, 70, 60, 0};
  char letter_grades[] = {'A', 'B', 'C', 'D', 'F'};
  
  double grade = s.final_grade;
  assert(grade >= 0);
  // find the index for the letter grade
  int i = 0;
  while(grade < numeric_grades[i]){
    ++i;
  }
  return letter_grades[i];
}

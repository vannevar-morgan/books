// source file for the grade-related functions

#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"
#include <algorithm>
#include <iostream>


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


double grade(const Student_info& s)
{
  return grade(s.midterm, s.final, s.homework);
}


/*
double grade_aux(const Student_info& s)
{
  try{
    return grade(s);
  }catch(domain_error){
    return grade(s.midterm, s.final, 0);
  }
}
*/


bool did_all_hw(const Student_info& s)
{
  //  std::cout << s.name << " did this many homeworks: " << s.homework.size() << std::endl;
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}


bool pgrade(const Student_info& s)
{
  return !fgrade(s);
}


bool fgrade(const Student_info& s)
{
  return grade(s) < 60;
}

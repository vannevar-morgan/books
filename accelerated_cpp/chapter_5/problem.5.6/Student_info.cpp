// source file for Student_info-related functions

#include "Student_info.h"
#include <iostream>
using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  std::cout << "Enter student name (ctrl-d to grade):" << std::endl;
  is >> s.name;
  std::cout << "Enter midterm exam grade for " << s.name << ":" << std::endl;
  is >> s.midterm;
  std::cout << "Enter final exam grade for " << s.name << ":" << std::endl;
  is >> s.final;

  std::cout << "Enter homework grades for " << s.name << ":" << std::endl;
  read_hw(is, s.homework);   // read and store all the student's homework grades
  return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
  if (in){
    // get rid of previous contents
    hw.clear();

    //read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    //clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}

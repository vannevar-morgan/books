#include "Student_info.h"
#include <vector>
#include <istream>
#include <algorithm>


bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}


std::istream& read(std::istream& is, Student_info& s)
{
  std::cout << "Enter student name: ";
  is >> s.name;
  std::cout << "Enter student midterm: ";
  is >> s.midterm;
  std::cout << "Enter student final: ";
  is >> s.final;
  std::cout << "Enter student hw grades: \n";
  read_hw(is, s.homework);

  return is;
}


std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
  if(in){
    hw.clear();

    double x;
    while(in >> x){
      hw.push_back(x);
    }

    in.clear();
  }

  return in;
}

bool did_all_hw(const Student_info& s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

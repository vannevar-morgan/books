
#include "Student_info.hpp"
//#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cstddef> // for size_t

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double hw);
double median(std::vector<double> vec);

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name() < y.name();
}

std::istream& Student_info::read(std::istream& in)
{
  in >> n >> midterm >> final;
  read_hw(in, homework);
  return in;
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

/*
double Student_info::grade() const
{
  return ::grade(midterm, final, homework);
}
*/

std::string Student_info::grade() const
{
  static const double nums[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
  static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};
  
  double numeric_grade = ::grade(midterm, final, homework);
  
  static const size_t n_grades = sizeof(nums) / sizeof(*nums);

  for(size_t i = 0; i < n_grades; ++i){
    if(numeric_grade >= nums[i]){
      return letters[i];
    }
  }

  // if numeric_grade is less than zero then throw std::domain_error exception.
  throw std::domain_error("tried to find letter grade but numeric grade is less than zero");
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
  if(hw.size() == 0){
    throw std::domain_error("student has done no homework");
  }
  return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double hw)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double median(std::vector<double> vec)
{
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  if(size == 0){
    throw std::domain_error("trying to take the median of an empty vector");
  }
  std::sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

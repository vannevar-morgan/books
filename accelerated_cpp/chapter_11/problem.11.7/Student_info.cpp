
#include "Vec.hpp"
#include "Student_info.hpp"
//#include <iostream>
#include <istream>
//#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

std::istream& read_hw(std::istream& in, Vec<double>& hw);
double grade(double midterm, double final, const Vec<double>& hw);
double grade(double midterm, double final, double hw);
double median(Vec<double> vec);

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

std::istream& read_hw(std::istream& in, Vec<double>& hw)
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

double Student_info::grade() const
{
  return ::grade(midterm, final, homework);
}

double grade(double midterm, double final, const Vec<double>& hw)
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

double median(Vec<double> v)
{
  typedef Vec<double>::size_type vec_sz;
  vec_sz size = v.size();
  if(size == 0){
    throw std::domain_error("trying to take the median of an empty vector");
  }
  std::sort(v.begin(), v.end());
  vec_sz mid = size / 2;

  return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

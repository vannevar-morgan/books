#include "Core.hpp"
#include "grading.hpp"
#include "median.hpp"
#include "ops.hpp"
#include <string>
#include <istream>
#include <vector>


std::string Core::name() const
{
  return n;
}

double Core::grade() const
{
  return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in)
{
  in >> n >> midterm >> final;
  return in;
}

std::istream& Core::read(std::istream& in)
{
  read_common(in);
  read_hw(in, homework);
  return in;
}


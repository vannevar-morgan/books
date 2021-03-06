#ifndef student_info_guard
#define student_info_guard

#include "Vec.hpp"
//#include <vector>
#include <string>
//#include <iostream>
#include <istream>

class Student_info
{
public:
  Student_info(): midterm(0), final(0) {}
  Student_info(std::istream& is) { read(is); }

  std::string name() const { return n; }
  bool valid() const { return !homework.empty(); }

  std::istream& read(std::istream&);
  double grade() const;

private:
  std::string n;
  double midterm;
  double final;
  Vec<double> homework;
  
};

bool compare(const Student_info&, const Student_info&);

#endif

#ifndef student_info_h
#define student_info_h

#include <string>
#include <vector>
#include <iostream>

struct Student_info
{
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool did_all_hw(const Student_info&);


#endif

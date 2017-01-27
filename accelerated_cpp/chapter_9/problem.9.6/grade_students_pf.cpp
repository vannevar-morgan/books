#include "Student_info_pf.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


int main(int argc, char* argv[])
{
  std::vector<Student_info_pf> students;
  Student_info_pf record;

  // read student info, find the maximum length name, grade students
  std::string::size_type maxlen = 0;
  while(record.read(std::cin)){
    record.grade();
    if(record.getName().size() > maxlen){
      maxlen = record.getName().size();
    } 
    students.push_back(record);
  }

  std::vector<Student_info_pf>::iterator iter = std::partition(students.begin(), students.end(), passed_class);
  std::sort(students.begin(), iter, compare_name);
  std::sort(iter, students.end(), compare_name);

  std::vector<Student_info_pf>::size_type i;
  for(i = 0; i != students.size(); ++i){
    std::cout << students[i].getName() << std::string(maxlen + 1 - students[i].getName().size(), ' ') << students[i].getGrade() << std::endl;
  }


  return 0;
}

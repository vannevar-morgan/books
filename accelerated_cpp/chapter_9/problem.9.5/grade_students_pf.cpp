#include "Student_info_pf.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


int main(int argc, char* argv[])
{
  std::vector<Student_info_pf> students;
  Student_info_pf record;

  while(record.read(std::cin)){
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), compare);
  

  std::string::size_type maxlen = 0;
  std::vector<Student_info_pf>::size_type i;
  for(i = 0; i != students.size(); ++i){
    if(students[i].getName().size() > maxlen){
      maxlen = students[i].getName().size();
    }    
  }

  for(i = 0; i != students.size(); ++i){
    std::cout << students[i].getName() << std::string(maxlen + 1 - students[i].getName().size(), ' ') << students[i].grade() << std::endl;
  }


  return 0;
}

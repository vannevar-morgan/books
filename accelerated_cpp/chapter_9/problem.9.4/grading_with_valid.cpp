#include "Student_info.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main(int argc, char* argv[])
{
  std::vector<Student_info> students;
  Student_info record;
  while(record.read(std::cin)){
    students.push_back(record);
  }

  std::sort(students.begin(), students.end(), compare);

  std::vector<Student_info>::size_type i;
  std::string::size_type maxlen = 0;
  for(i = 0; i != students.size(); ++i){
    if(students[i].name().size() > maxlen){
      maxlen = students[i].name().size();
    }
  }
  
  std::cout << "\n\n\n";
  for(i = 0; i != students.size(); ++i){
    if(students[i].valid()){
      std::cout << students[i].name() << std::string(maxlen + 1 - students[i].name().size(), ' ') << students[i].grade() << std::endl;
    }else{
      std::cout << students[i].name() << " did no homework so no grade was calculated..." << std::endl;
    }
  }
    
  return 0;
}

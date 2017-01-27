#include "Student_info.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0;

  while(record.read(std::cin)){
    maxlen = std::max(maxlen, record.name().size());
    students.push_back(record);
  }
  
  std::sort(students.begin(), students.end(), compare);
  
  for(std::vector<Student_info>::size_type i = 0; i != students.size(); ++i){
    std::cout << students[i].name() << std::string(maxlen + 1 - students[i].name().size(), ' ');
    
    try{
      std::string final_grade = students[i].grade();
      std::cout << final_grade << std::endl;
    }catch (std::domain_error e){
      std::cout << e.what() << std::endl;
    }
    
  }


  return 0;
}

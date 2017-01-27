#include "Student_info.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0;

  while(record.read(std::cin)){
    maxlen = std::max(maxlen, record.name().size());
    students.push_back(record);
  }
  
  std::cout << "sorting students..." << std::endl;
  std::sort(students.begin(), students.end(), compare);
  std::cout << "finished sorting students..." << std::endl;
  
  for(std::vector<Student_info>::size_type i = 0; i != students.size(); ++i){
    std::cout << students[i].name() << std::string(maxlen + 1 - students[i].name().size(), ' ');
    
    try{
      double final_grade = students[i].grade();
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3) << final_grade << std::setprecision(prec) << std::endl;
    }catch (std::domain_error e){
      std::cout << e.what() << std::endl;
    }
    
  }

  // print the created / copied / assigned / destroyed statistics
  std::cout << "\ncreated: " << students[0].get_created() << std::endl;
  std::cout << "copied: " << students[0].get_copied() << std::endl;
  std::cout << "assigned: " << students[0].get_assigned() << std::endl;
  std::cout << "destroyed: " << students[0].get_destroyed() << std::endl << std::endl;

  return 0;
}

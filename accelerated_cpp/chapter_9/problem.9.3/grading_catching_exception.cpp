#include <iostream>
#include "Student_info.hpp"
#include <stdexcept>


int main(int argc, char* argv[])
{
  Student_info student;
  try{
    student.grade();
  }catch(std::domain_error e){
    std::cout << "There was an error grading the student...\n" << e.what() << std::endl;
    return -1;
  }
  
  return 0;
}

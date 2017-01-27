// Problem 8.1
//
// This uses a template function to implement the grading behaviour of the analysis functions on page 110 (6.2)

#include "Student_info.h"
#include <vector>
#include <iostream>
#include "analysis_schemes.h"
#include "analysis.h"

void write_analysis(std::ostream& out, const std::string& name, double scheme(const Student_info&), const std::vector<Student_info>& did, const std::vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did.begin(), did.end(), scheme) << ", median(didnt) = " << analysis(didnt.begin(), didnt.end(), scheme) << std::endl;
}

int main()
{
  // vectors for students who did and didn't do all homework
  std::vector<Student_info> did, didnt;
  
  // read all the student records and partition them
  Student_info student;
  while(read(std::cin, student)){
    if(did_all_hw(student)){
      did.push_back(student);
    }else{
      didnt.push_back(student);
    }
  }

  // verify that all analyses will show us something
  if(did.empty()){
    std::cout << "No student did all the homework!\n";
    return 1;
  }

  if(didnt.empty()){
    std::cout << "Every student did all the homework!\n";
    return 1;
  }

  // do the analyses
  write_analysis(std::cout, "median", median_grade, did, didnt);



  
  return 0;
}

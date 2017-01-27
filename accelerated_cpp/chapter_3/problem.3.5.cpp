#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<std::string> students;
std::vector<double> grades;
std::string name;
double midterm_exam, final_exam, final_grade;

double calc_grade(double, double);

int main()
{
  // get the list of student names
  std::cout << "Please enter all of the student names: " << std::endl;
  while(std::cin >> name){
    students.push_back(name);
  }

  // sort the students alphabetically
  sort(students.begin(), students.end());

  std::cout << "\nOk, let's enter grades now... (press enter)" << std::endl;
  // need to reset cin to start reading in grades
  if(!std::cin){
    std::cin.clear();
    std::string reset_buffer;
    std::getline(std::cin, reset_buffer);
  }
  
  // get grades for each student
  std::vector<std::string>::const_iterator iter;
  for(iter = students.begin(); iter != students.end(); ++iter){
    std::cout << "What did " << *iter << " score on the midterm exam?" << "\t";
    std::cin >> midterm_exam;
    std::cout << "What did " << *iter << " score on the final exam?" << "\t";
    std::cin >> final_exam;
    final_grade = calc_grade(midterm_exam, final_exam);
    grades.push_back(final_grade);
  }

  // print the name and grade for each student, in alphabetical order
  std::cout << "\nThese are the final grades for all students, listed alphabetically." << std::endl << std::endl;
  std::vector<double>::const_iterator grade_iter = grades.begin();
  for(iter = students.begin(); iter != students.end(); ++iter){
    std::cout << *iter << "\t" << *grade_iter << std::endl;
    ++grade_iter;
  }

  /*
  std::cout << "These are the students: " << std::endl;
  std::vector<std::string>::const_iterator iter;
  for(iter = students.begin(); iter != students.end(); ++iter){
    std::cout << *iter << std::endl;
  }
  */

  return 0;
}

double calc_grade(double midterm, double final)
{
  return 0.35*midterm + 0.65*final;
}

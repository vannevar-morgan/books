/*
 * Example of pointers usage.  Takes a numeric grade and returns a letter grade
 * using two arrays.  Illustrates use of sizeof() to determine the number of 
 * elements in an array.
 *
 * Page 178, Section 10.3, Accelerated C++
 */

#include <iostream>
#include <string>
#include <cstddef>

std::string letter_grade(double grade);

int main()
{
  double n;
  std::cout << "enter a numeric grade to find the letter grade: ";
  std::cin >> n;

  std::cout << "letter grade is: " << letter_grade(n) << std::endl;  

  return 0;
}

std::string letter_grade(double grade)
{
  // ranges for numeric grades
  static const double numbers[] = {97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};
  
  // letter grade values
  static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

  // number of grade values
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

  // return the letter grade corresponding to the numeric grade
  for(size_t i = 0; i < ngrades; ++i){
    if(grade >= numbers[i]){
      return letters[i];
    }
  }

  // if the grade was out of range then return "?/?/?" to notify
  return "?/?/?";
}

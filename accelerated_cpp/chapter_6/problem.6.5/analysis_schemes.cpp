#include "analysis_schemes.h"
#include "Student_info.h"
#include "grade.h"
#include <stdexcept>  // for exception classes
#include "average.h"  // for average()
#include <algorithm>  // for remove_copy(), transform()
#include <iterator>  // for back_inserter()
#include "median.h"  // for median()

/*
double median_grade(const Student_info& s)
{
  // this is grade_aux(), pg 113
  try{
    return grade(s);
  }catch(std::domain_error){
    return grade(s.midterm, s.final, 0);
  }
}
*/


double median_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;
  
  transform(students.begin(), students.end(), std::back_inserter(grades), grade_aux);
  
  return median(grades);
}


double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
}


double average_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;
  
  transform(students.begin(), students.end(), std::back_inserter(grades), average_grade);
  
  return median(grades);
}


double optimistic_median(const Student_info& s)
{
  std::vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

  if(nonzero.empty()){
    return grade(s.midterm, s.final, 0);
  }else{
    return grade(s.midterm, s.final, median(nonzero));
  }
}


double optimistic_median_analysis(const std::vector<Student_info>& students)
{
  std::vector<double> grades;
  
  transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
  
  return median(grades);
}


void write_analysis(std::ostream& out, const std::string& name,
		    double analysis(const std::vector<Student_info>&),
		    const std::vector<Student_info>& did,
		    const std::vector<Student_info>& didnt)
{
  out << name << ": median(did) = " << analysis(did) 
      << ", median(didnt) = " << analysis(didnt) << std::endl;
}

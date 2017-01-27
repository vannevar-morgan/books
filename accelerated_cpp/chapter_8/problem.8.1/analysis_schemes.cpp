#include "analysis_schemes.h"
#include "Student_info.h"
#include "grade.h"
#include <stdexcept>  // for exception classes
#include "average.h"  // for average()
#include <algorithm>  // for remove_copy()
#include <iterator>  // for back_inserter()
#include "median.h"  // for median()


double median_grade(const Student_info& s)
{
  // this is grade_aux(), pg 113
  try{
    return grade(s);
  }catch(std::domain_error){
    return grade(s.midterm, s.final, 0);
  }
}

double average_grade(const Student_info& s)
{
  return grade(s.midterm, s.final, average(s.homework));
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

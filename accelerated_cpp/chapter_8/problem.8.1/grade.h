#ifndef grade_h
#define grade_h

#include "Student_info.h"
#include <vector>  // for vector

double grade(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);


#endif

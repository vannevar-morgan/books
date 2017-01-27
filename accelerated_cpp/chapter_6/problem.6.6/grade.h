#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

//double grade_aux(const Student_info& s);

bool did_all_hw(const Student_info& s);

bool pgrade(const Student_info& s);
bool fgrade(const Student_info& s);

#endif

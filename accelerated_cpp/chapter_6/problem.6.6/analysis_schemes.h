#ifndef analysis_schemes_h
#define analysis_schemes_h

#include "Student_info.h"
#include <ostream>
#include <string>
#include <vector>

double median_grade(const Student_info&);
//double median_analysis(const std::vector<Student_info>& students);

double average_grade(const Student_info&);
//double average_analysis(const std::vector<Student_info>& students);

double optimistic_median(const Student_info&);
//double optimistic_median_analysis(const std::vector<Student_info>& students);

double make_analysis(const std::vector<Student_info>& students, double grade_student(const Student_info& s));

/*
void write_analysis(std::ostream& out, const std::string& name,
		    double analysis(const std::vector<Student_info>&),
		    const std::vector<Student_info>& did,
		    const std::vector<Student_info>& didnt);
*/

void write_analysis(std::ostream& out, const std::string& name,
		    double analysis(const Student_info&),
		    const std::vector<Student_info>& did,
		    const std::vector<Student_info>& didnt);


#endif

#ifndef guard_ops_hpp
#define guard_ops_hpp

#include <istream>
#include <vector>
#include "Core.hpp"
#include "Ptr.hpp"

std::istream& read_hw(std::istream& in, std::vector<double>& hw);

bool compare_Core_ptrs(const Ptr<Core>& student1, const Ptr<Core>& student2);

#endif

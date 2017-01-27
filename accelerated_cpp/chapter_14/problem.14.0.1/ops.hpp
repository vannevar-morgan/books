#ifndef guard_ops_hpp
#define guard_ops_hpp

#include <istream>
#include <vector>
#include "Core.hpp"
#include "Handle.hpp"

std::istream& read_hw(std::istream& in, std::vector<double>& hw);

bool compare_Core_handles(const Handle<Core>& student1, const Handle<Core>& student2);

#endif

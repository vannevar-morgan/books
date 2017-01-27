#ifndef parsing_h
#define parsing_h

#include <string>
#include <vector>

bool bracketed(const std::string&);
bool space(char);
bool not_space(char);
std::vector<std::string> split(const std::string&);

#endif

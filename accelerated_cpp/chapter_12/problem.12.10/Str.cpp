#include "Str.hpp" // for Str
#include <istream> // for istream
#include <ostream> // for ostream
#include <cctype> // for isspace()

std::istream& operator>>(std::istream& is, Str& s)
{
  s.data.clear();
  
  char c;
  while(is.get(c) && isspace(c)){}

  if(is){
    do s.data.push_back(c);
    while(is.get(c) && !isspace(c));

    if(is){
      is.unget();
    }
  }

  return is;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
  for(Str::size_type i = 0; i != s.size(); ++i){
    os << s[i];
  }
  return os;
}

Str operator+(const Str& left, const Str& right)
{
  Str temp_str = left;
  temp_str += right;
  return temp_str;
}

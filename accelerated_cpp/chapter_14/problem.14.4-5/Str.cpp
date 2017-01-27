#include "Vec.hpp" // for Vec
#include "Str.hpp" // for Str
#include <istream> // for istream
#include <ostream> // for ostream
#include <cctype> // for isspace()
#include <cstring> // for std::strlen(), std::strcmp()


std::istream& operator>>(std::istream& is, Str& s)
{
  s.data.make_unique();
  s.data->clear();
  
  char c;
  while(is.get(c) && isspace(c)){}

  if(is){
    do s.data->push_back(c);
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

Str operator+ (const Str& left, const Str& right)
{
  Str temp_str = left;
  temp_str += right;
  return temp_str;
}

Str operator+ (const Str& left, const char* right)
{
  Str temp = left;
  return temp += right;
}

Str operator+ (const char* left, const Str& right)
{
  Str::size_type str_sz = std::strlen(left);
  Str temp(left, left + str_sz);
  return temp += right;
}

//////////////////////////////////////////////
//////////////////////////////////////////////
// The following functions rely on c_str(). //
// Commented out because c_str is not       //
// currently implemented.                   //
//////////////////////////////////////////////
//////////////////////////////////////////////


// bool operator< (const Str& left, const Str& right)
// {
//   if( std::strcmp(left.c_str(), right.c_str()) < 0 ){
//     return true;
//   }
//   return false;
// }

// bool operator> (const Str& left, const Str& right)
// {
//   if( std::strcmp(left.c_str(), right.c_str()) > 0 ){
//     return true;
//   }
//   return false;
// }

// bool operator<= (const Str& left, const Str& right)
// {
//   if( !(std::strcmp(left.c_str(), right.c_str()) > 0) ){
//     return true;
//   }
//   return false;
// }

// bool operator>= (const Str& left, const Str& right)
// {
//   if( !(std::strcmp(left.c_str(), right.c_str()) < 0) ){
//     return true;
//   }
//   return false;
// }

// bool operator== (const Str& left, const Str& right)
// {
//   return !std::strcmp(left.c_str(), right.c_str());
// }

// bool operator!= (const Str& left, const Str& right)
// {
//   return std::strcmp(left.c_str(), right.c_str());
// }

std::istream& getline(std::istream& is, Str& s, char delim)
{
  s.clear();
  char c;
  Vec<char> line_data;
  while(is.get(c) && c != delim){
    line_data.push_back(c);
  }
  Str temp(line_data.begin(), line_data.end());
  s = temp;

  return is;
}

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
#include "parsing.h"


bool bracketed(const std::string& s)
{
  return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

std::vector<std::string> split(const std::string& str)
{
  typedef std::string::const_iterator iter;
  std::vector<std::string> ret;

  iter i = str.begin();
  while(i != str.end()){
    // ignore leading blanks
    i = find_if(i, str.end(), not_space);

    // find end of next word
    iter j = find_if(i, str.end(), space);

    // copy the characters in [i, j)
    if(i != str.end()){
      ret.push_back(std::string(i, j));
    }

    i = j;
  }

  return ret;
}

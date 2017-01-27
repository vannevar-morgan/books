#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>

/*
bool isspace(char c)
{
  return c == ' ';
}
*/

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

template <class Out>
void split(const std::string& str, Out os)
{
  typedef std::string::const_iterator iter;
  iter i = str.begin();
  while(i != str.end()){
    // ignore leading blanks
    i = std::find_if(i, str.end(), not_space);
    
    // find end of next word
    iter j = std::find_if(i, str.end(), space);

    // copy the characters in [i, j)
    if(i != str.end()){
      *os++ = std::string(i, j);
    }

    i = j;
  }
}


int main()
{
  // split text from user input
  std::cout << "enter some text to split: " << std::endl;
  std::string s;
  while(std::getline(std::cin, s)){
    split(s, std::ostream_iterator<std::string>(std::cout, "\n"));
  }
  return 0;
}

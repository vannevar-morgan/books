#include <iostream>

int main()
{
  /* This is a comment that extends over several lines
     because it uses /* and */ as its starting and ending delimiters */
    std::cout << "Does this work?" << std::endl;
  return 0;
}


//
// Multiline comments aren't balanced,
// Multiline comment comments everything between /* and */
// so /*.../*... */...*/ doesn't work.
//
// No nested comments.
//

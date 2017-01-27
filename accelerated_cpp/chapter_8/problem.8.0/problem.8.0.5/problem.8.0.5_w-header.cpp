/*
  This program implements various algorithms of the STL.  It's just practice for writing template functions.  The template functions are defined in template_defs.hpp
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include "template_defs.hpp"

int main()
{
  std::cout << "This program implements the \"replace\" algorithm of the STL." << std::endl;
  std::vector<int> set_a;
  std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(set_a));

  std::cout << "\n\n" << "This is the data that I read: " << std::endl;
  std::copy(set_a.begin(), set_a.end(), std::ostream_iterator<int>(std::cout, " "));

  new_replace(set_a.begin(), set_a.end(), 24, 0);
  std::cout << std::endl << "This is the data after I replaced all instances of \"24\" with \"0\": " << std::endl;
  std::copy(set_a.begin(), set_a.end(), std::ostream_iterator<int>(std::cout, " "));

  std::cout << std::endl << "This is the data after I reverse the vector: " << std::endl;
  new_reverse(set_a.begin(), set_a.end());
  std::copy(set_a.begin(), set_a.end(), std::ostream_iterator<int>(std::cout, " "));

  std::cout << std::endl;
  return 0;
}

#include <istream>
#include <string>
#include <iostream>
#include <vector>
#include "grammar.h"
#include "parsing.h"


Grammar read_grammar(std::istream& in)
{
  Grammar ret;
  std::string line;

  // read the input
  while(std::getline(std::cin, line)){
    // split the input into words
    std::vector<std::string> entry = split(line);

    if(!entry.empty()){
      // use the category to store the associated rule
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
  }

  return ret;
}

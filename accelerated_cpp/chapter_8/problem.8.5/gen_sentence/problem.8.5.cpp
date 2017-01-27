#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "gen_sentence.h"
#include "grammar.h"


int main()
{
  // init prng with srand()
  srand(time(0) ^ getpid());

  // toggle to test using the output iterator attached to standard output
  // or to test using the output iterator that stores results in a list.
  bool test_with_list = false;

  // generate the sentence.
  if(test_with_list){
    std::list<std::string> sentence;
    gen_sentence(read_grammar(std::cin), std::back_inserter(sentence));
    std::ostream_iterator<std::string> os(std::cout, " ");
    std::copy(sentence.begin(), sentence.end(), os);
  }else{
    gen_sentence(read_grammar(std::cin), std::ostream_iterator<std::string>(std::cout, " "));
  }

  std::cout << std::endl;
  return 0;
}

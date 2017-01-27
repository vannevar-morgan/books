#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "gen_sentence.h"
#include "grammar.h"


using namespace std;

int main()
{
  // init prng with srand()
  srand(time(0) ^ getpid());

  // generate the sentence
  vector<string> sentence = gen_sentence(read_grammar(cin));

  // write the first word, if any
  vector<string>::const_iterator it = sentence.begin();
  if(!sentence.empty()){
    cout << *it;
    ++it;
  }

  // write the rest of the words, each preceded by a space
  while(it != sentence.end()){
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;
}

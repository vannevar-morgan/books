#ifndef gen_sentence_h
#define gen_sentence_h

#include <string>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "grammar.h"
#include "parsing.h"
#include "nrand.h"


template <class Out>
void gen_aux(const Grammar& g, const std::string& word, Out os)
{
  if(!bracketed(word)){
    *os++ = word;
  }else{
    // locate the rule that corresponds to word
    Grammar::const_iterator it = g.find(word);
    if(it == g.end()){
      throw std::logic_error("empty rule");
    }

    // fetch the set of possible rules
    const Rule_collection& c = it->second;

    // from which we select one at random
    const Rule& r = c[nrand(c.size())];
    //std::cout << "# of rules: " << c.size() << "\n";
    

    // recursively expand the selected rule
    for(Rule::const_iterator i = r.begin(); i != r.end(); ++i){
      //std::cout << *i << "\n";
      gen_aux(g, *i, os);
    }

  }
}


template <class Out>
void gen_sentence(const Grammar& g, Out os)
{
  gen_aux(g, "<sentence>", os);
}

#endif

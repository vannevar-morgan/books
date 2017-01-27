#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>
//#include <iostream>
#include "grammar.h"
#include "parsing.h"
#include "nrand.h"
#include "gen_sentence.h"


void gen_aux(const Grammar& g, const std::string& word, std::list<std::string>& ret)
{
  if(!bracketed(word)){
    ret.push_back(word);
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
      gen_aux(g, *i, ret);
    }

  }
}


std::list<std::string> gen_sentence(const Grammar& g)
{
  std::list<std::string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

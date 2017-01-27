#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include "grammar.h"
#include "parsing.h"
#include "nrand.h"
#include "gen_sentence.h"


void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret)
{
  if(!bracketed(word)){
    ret.push_back(word);
  }else{
    std::vector<std::string> op_stack;
    op_stack.push_back(word);
    while(!op_stack.empty()){
      // print the current op_stack to illustrate how the stack works.
      std::cout << "current op_stack: " << std::endl;
      for(auto i = op_stack.rbegin(); i != op_stack.rend(); ++i){
	std::cout << *i << std::endl;
      }
      std::cout << std::endl;

      // locate the rule that corresponds to the current word on the op_stack
      Grammar::const_iterator it = g.find(op_stack.back());
      op_stack.pop_back(); // pop the current frame of the op_stack
      if(it == g.end()){
        throw std::logic_error("empty rule");
      }

      // fetch the set of possible rules
      const Rule_collection& c = it->second;

      // from which we select one at random
      const Rule& r = c[nrand(c.size())];
      //std::cout << "# of rules: " << c.size() << "\n";
      

      // process the rule for the current op_stack frame
      std::vector<std::string> temp_stack;
      for(Rule::const_iterator i = r.begin(); i != r.end(); ++i){
        if(!bracketed(*i)){
	  ret.push_back(*i); // if the words isn't a rule, push it to the return vector
	}else{
	  temp_stack.push_back(*i); // if the word is a rule, push it to the temp_stack
	}
      }
      //
      // The temporary stack needs to be copied to the op_stack in reverse order because
      // the op_stack is processed LIFO but the rule must be processed FIFO orelse the 
      // generated sentence will be jumbled.
      // (the stack frames (the rules) would be reversed for each rule expansion)
      //
      std::reverse_copy(temp_stack.begin(), temp_stack.end(), std::back_inserter(op_stack));
    }
    
  }
}


std::vector<std::string> gen_sentence(const Grammar& g)
{
  std::vector<std::string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

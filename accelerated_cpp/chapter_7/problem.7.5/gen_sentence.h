#ifndef gen_sentence_h
#define gen_sentence_h

#include <list>
#include <string>
#include "grammar.h"


void gen_aux(const Grammar& g, const std::string& word, std::list<std::string>& ret);

std::list<std::string> gen_sentence(const Grammar& g);


#endif

#ifndef gen_sentence_h
#define gen_sentence_h

#include <vector>
#include <string>
#include "grammar.h"


void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret);

std::vector<std::string> gen_sentence(const Grammar& g);


#endif

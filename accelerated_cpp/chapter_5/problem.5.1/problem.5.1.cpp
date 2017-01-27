/* 
 * Accelerated C++
 * Chapter 5, Problem 1
 * 
 * November 16, 2015
 * 
 * Implements a permuted index.
 * Collects text from the user and indexes the text by all words in the text (creates a permuted index).
 * 
 * Allows searching the text for any word in the text and returns all instances of the word along with 
 * the context it was used in.
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef vector<vector<string> > permuted_index;

permuted_index makePermutedIndex(const vector<string>& phrases);
vector<string> split(const string& s, const char c);
vector<string> find_matches(const permuted_index& pidx, const string& query);


int main()
{
  vector<string> input_lines;
  string s;
  cout << "enter some text to generate a permuted index: " << endl;
  while(getline(cin, s)){
    input_lines.push_back(s);
  }
  
  permuted_index phrase_map = makePermutedIndex(input_lines);
  
  cin.clear();
  cout << endl << "enter a search term to look for matches in the permuted index: " << endl;
  cin >> s;
  vector<string> matches = find_matches(phrase_map, s);
  for(vector<string>::size_type i = 0; i < matches.size(); ++i){
    cout << matches[i] << "\n" << endl;
  }
  
  return 0;
}

vector<string> find_matches(const permuted_index& pidx, const string& query)
{
  vector<string> matches;
  for(permuted_index::size_type i = 0; i < pidx.size(); ++i){
    string match = "";
    auto words = pidx[i];
    // search all words in the phrase for the query term
    for(vector<string>::size_type j = 0; j < words.size(); ++j){
      if(query == words[j]){
	// append words before the query
	for(vector<string>::size_type k = 0; k < j; ++k){
	  match += words[k];
	  match += ' ';
	}
	// append tab character
	match += "\t\t";
	// append query and following words
	for(vector<string>::size_type k = j; k < words.size(); ++k){
	  match += words[k];
	  match += ' ';
	}
	matches.push_back(match);
	match = "";
      }
    }
  }
  
  return matches;
}

permuted_index makePermutedIndex(const vector<string>& phrases)
{
  permuted_index pidx;
  for(vector<string>::size_type i = 0; i < phrases.size(); ++i){
    pidx.push_back(split(phrases[i], ' '));
  }
  
  return pidx;
}

vector<string> split(const string& s, const char c)
{
  vector<string> words;
  string::size_type beg = 0;
  string::size_type end = 0;
  while(beg < s.size()){
    while(beg < s.size() && s[beg] == c) { ++beg; } // scroll through leading whitespace
    end = beg;
    
    while(end < s.size() && s[end] != c) { ++end; } // scroll through non-whitespace
    words.push_back(s.substr(beg, end - beg));
    beg = end;
  }
  
  return words;
}

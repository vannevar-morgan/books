#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::ifstream;
using std::max;

void get_input(const string& filename, vector<string>& words)
{
  // read words from a dictionary wordlist

  string line;
  ifstream dictionary (filename.c_str());
  if (dictionary.is_open())
  {
    while ( getline (dictionary,line) )
    {
      words.push_back(line);
    }
    dictionary.close();
  }

  else cout << "Unable to open dictionary file"; 
}

void stringToUpper(string& word)
{
  string::size_type i = word.size();
  string::size_type j = 0;
  while (j != i) {
    word[j] = toupper(word[j]);
    ++j;
  }
}

void reverseWord(string& word)
{
  string word_copy = word;
  string::size_type i = word.size();
  string::size_type j = 0;
  word = "";
  while (i != j) {
    --i;
    word = word + word_copy[i];
  }
}

void find_palindromes(const vector<string>& words, vector<string>& palindromes)
{
  vector<string>::const_iterator it = words.begin();
  string forward, reverse;
  while (it != words.end()) {
    forward = *it;
    stringToUpper(forward);
    reverse = forward;
    reverseWord(reverse);
    if (forward.compare(reverse) == 0)
      palindromes.push_back(*it);
    ++it;
  }
}

int main(int argc, char** argv)
{
  if(argc != 2){
    cout << "usage: ./palindromes dictionary_filename" << endl;
    return -1;
  }
  
  // import the dictionary file
  string wordlist = argv[1]; // wordlist filename
  vector<string> words;
  get_input(wordlist, words);

  // find palindromes
  vector<string> palindromes;
  find_palindromes(words, palindromes);
  
  // find the length of the longest palindrome
  vector<string>::const_iterator it = palindromes.begin();
  string::size_type max_len = 0;
  cout << "all palindromes: " << endl;
  while (it != palindromes.end()) {
    cout << *it << endl;
    max_len = max(max_len, (*it).size());
    ++it;
  }

  // find all palindromes that are the length of the longest palindrome
  it = palindromes.begin();
  vector<string> longest_palindromes;
  while(it != palindromes.end()){
    if(max_len == it->size()){
      longest_palindromes.push_back(*it);
    }
    ++it;
  }
  
  // print results
  cout << "\nMax Palindrome length is " << max_len << endl;
  cout << "\nPalindromes of length " << max_len << ": " << endl;
  for(vector<string>::size_type i = 0; i < longest_palindromes.size(); ++i){
    cout << longest_palindromes[i] << endl;
  }
  
  return 0;
}

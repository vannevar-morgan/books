// ************************************************************
//              Name:  vann
//          Filename:  problem.5.11.cpp
//           Project:  --Accelerated C++, Problem 5.11--
//       
//      Date written:  Wednesday, November 23, 2016
//
//     --Code Summary--
// Determines whether a user supplied word has any ascending or
// descending letters.
//
// If the user specifies a wordlist file as a second argument 
// then it's assumed to be an english dictionary and outputs 
// the longest word in the english dictionary with no ascenders
// or descenders.  In this case, the word for the first 
// argument will not be checked for ascenders or descenders.
//
// All words in the dictionary will be treated as lowercase.
//
// Ascenders: "bdfhklt"
// Descenders: "gjpqy"
// ************************************************************
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int check_asc_desc(const string& word);
bool search_chars_in_string(const string& word, const string& keys);
void do_wordlist_check(const string& wl_filename);
void read_wordlist(const string& filename, vector<string>& words);
void do_asc_desc_check(const string& word);
bool compare_word_lengths(const string& a, const string& b);


int main(int argc, char* argv[]){
  string USAGE_MESSAGE = "usage: ./asc_desc word (dictionary_file)";
  if(argc != 2 && argc != 3){
    cout << USAGE_MESSAGE << endl;
    return 0;
  }
  const string word(argv[1]);
  if(argc == 3){
    // import wordlist and print the longest word(s) with no ascenders or descenders
    const string wl_filename(argv[2]);
    do_wordlist_check(wl_filename);
  }else{
    // check word for ascenders and descenders
    do_asc_desc_check(word);
  }
  
  return 0;
}


void do_wordlist_check(const string& wl_filename){
  //
  // Import wordlist and print the longest word(s) in the English 
  // language with no ascenders or descenders.
  //
  vector<string> words;
  read_wordlist(wl_filename, words);
  // find words with no ascenders or descenders
  vector<string> no_ad_words;
  for(const string& s : words){
    if(!check_asc_desc(s)){
      no_ad_words.push_back(s);
    }
  }
  // sort the words in decreasing order of word length
  std::sort(no_ad_words.begin(), no_ad_words.end(), compare_word_lengths);
  // find the longest words of those with no ascenders or descenders
  string::size_type max_len = no_ad_words.begin()->size();
  vector<string>::size_type num_strings = 0;
  for(const string& s : no_ad_words){
    if(s.size() < max_len){
      break;
    }
    ++num_strings;
  }
  no_ad_words.resize(num_strings);
  // print the longest words
  cout << "longest string(s): " << endl;
  for(const string& s : no_ad_words){
    cout << s << endl;
  }

}


bool compare_word_lengths(const string& a, const string& b){
  //
  // Comparison to sort strings in descending order of string lengths.
  //
  return a.size() > b.size();
}


class Open_Wordlist{
  // Wrapper class to manage the wordlist file.
public:
  Open_Wordlist(const string& filename){
    in_file.open(filename.c_str());
  }
  
  ~Open_Wordlist(){
    in_file.close();
  }
  
  bool getline(std::string& buffer){
    return std::getline(in_file, buffer);
  }
  
private:
  std::ifstream in_file;
};


void read_wordlist(const string& filename, vector<string>& words){
  //
  // Import the wordlist into "words".
  //
  Open_Wordlist wl(filename.c_str());
  string s;
  while(wl.getline(s)){
    words.push_back(s);
  }
}


void do_asc_desc_check(const string& word){
  //
  // Check "word" for ascenders and descenders.
  // Print results.
  //
  int check_code = check_asc_desc(word);
  if(!check_code){
    cout << "\"" << word << "\" has no ascenders or descenders..." << endl;
  }else if(check_code == 1){
    cout << "\"" << word << "\" has ascenders..." << endl;
  }else if(check_code == 2){
    cout << "\"" << word << "\" has descenders..." << endl;
  }else if(check_code == 3){
    cout << "\"" << word << "\" has both ascenders and descenders..." << endl;
  }
}


int check_asc_desc(const string& word){
  //
  // Checks if "word" has ascenders or descenders.
  // Returns:
  //   0  =>  if neither ascenders nor descenders are present.
  //   1  =>  if only ascenders.
  //   2  =>  if only descenders.
  //   3  =>  if both ascenders and descenders.
  //
  const string ascenders = "bdfhklt";
  const string descenders = "gjpqy";
  // convert word to lowercase
  string lc_word = word;
  std::transform(lc_word.begin(), lc_word.end(), lc_word.begin(), ::tolower);
  // check ascenders
  int check_val = 0;
  if(search_chars_in_string(lc_word, ascenders)){
    check_val += 1;
  }
  // check descenders
  if(search_chars_in_string(lc_word, descenders)){
    check_val += 2;
  }
  return check_val;
}


bool search_chars_in_string(const string& word, const string& keys){
  //
  // Searches for any character in "keys" in string "word".
  // Returns true if word contains any character in "keys", false otherwise.
  //
  for(const char c : keys){
    if(word.find(c) != string::npos){
      return true;
    }
  }
  return false;
}

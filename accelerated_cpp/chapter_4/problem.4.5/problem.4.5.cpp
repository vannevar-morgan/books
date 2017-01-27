#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// -Gets some words from the user using the get_input() function.
// -Echoes the words entered back to the user.
// -Displays a total word count.
// -Displays a word count for each unique word.

void get_input(std::istream& in, std::vector<std::string>& data){
  std::string temp;
  while(in >> temp){
    data.push_back(temp);
  }
}

int main(){
  // get words from user
  std::vector<std::string> words;
  std::cout << "enter some words: " << std::endl;
  get_input(std::cin, words);
  
  // echo back words entered
  std::cout << "\nthis is what you entered: " << std::endl;
  for(const std::string s : words){
    std::cout << s << std::endl;
  }
  
  // print out the total number of words entered
  std::cout << "\nyou entered " << words.size() << " words." << std::endl;
  
  // print out word counts for unique words
  std::map<std::string, int> word_counts;
  for(const std::string s : words){
    word_counts[s]++;
  }
  
  std::cout << "\nhere's a word count for the words you entered: " << std::endl;
  
  sort(words.begin(), words.end());
  std::vector<std::string> unique_words;
  unique_copy(words.begin(), words.end(), back_inserter(unique_words));
  
  for(const std::string s : unique_words){
    std::cout << s << ":\t" << word_counts[s] << std::endl;
  }
  
  return 0;
}

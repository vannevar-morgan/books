/* $3.e/49
   Problem 3-3
   This program takes a string input and returns the number of times each distinct word appears in its input.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

inline vector<string> split_string(const string&, const char*);   // forward declaration of an inline function to be defined


int main(){

  // Get a string input from the user and save it to a vector
  cout << "\nEnter a string: " << endl;
  vector<string> usr_input;
  string cmd_line_temp;
  while (cin >> cmd_line_temp){
    usr_input.push_back(cmd_line_temp);
  }

  // Check to make sure the user entered something
  typedef vector<string>::size_type str_vec_size;
  str_vec_size data_size = usr_input.size();

  if (data_size == 0){
    cout << "\nYou didn't enter anything..." << endl;
    return 1;
  }

  // Parse each entry by whitespace, commas, periods, colons, semicolons
  vector<string> words;
  vector<string> temp_vector;
  const char tokens[] = {' ', ',', '.', ';', ':', '?', '/'};

  for (str_vec_size i = 0 ; i != data_size; ++i){
    temp_vector = split_string(usr_input[i], tokens);
    words.insert( words.end(), temp_vector.begin(), temp_vector.end() );
  }

  // Print the data to screen
  cout << "\nThese are the words you entered: " << endl;
  data_size = words.size();
  for (str_vec_size i = 0; i != data_size; ++i){
    cout << "\t" << words[i] << endl;
  }

  // Count the instances of each word
  sort(words.begin(), words.end());   // sort the words alphabetically so that duplicates follow each other
  
  int count = 1;
  vector<int> word_counts;
  vector<string> unique_words;
  unique_words.push_back(words[0]); // we have already checked that the user input at least one word
  
  for (str_vec_size i = 1; i != data_size; ++i){
    if (words[i].compare(words[i-1]) == 0){ // if the string of the current element is the same as the string of the previous element
      count += 1;
    }else{ // if we have a unique word
      unique_words.push_back(words[i]);
      word_counts.push_back(count);
      count = 1;
    }
  }
  word_counts.push_back(count);

  // Print the data to screen
  cout << "\nThese are the instances of each unique word: " << endl;
  data_size = unique_words.size();
  for (str_vec_size i = 0; i != data_size; ++i){
    cout << "\t" << word_counts[i] << "\t" << unique_words[i] << endl;
  }

}


inline vector<string> split_string(const string &source, const char *delimiter)
{
  vector<string> results;
  
  size_t prev = 0;
  size_t next = 0;
  
  while ((next = source.find_first_of(delimiter, prev)) != string::npos)
    {
      if (next - prev != 0)
	{
	  results.push_back(source.substr(prev, next - prev));
        }
      prev = next + 1;
    }
  
  if (prev < source.size())
    {
      results.push_back(source.substr(prev));
    }
  
  return results;
}

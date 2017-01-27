/* $3.e/49
   Problem 3-4
   This program takes a string input and returns the length of the longest and the shortest string in its input.
*/

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::max_element;
using std::min_element;
using std::distance;

int main()
{
  cout << "Provide an input followed by EOF: " << endl;

  // Get the input for any number of strings
  vector<string> words;
  string temp_var;
  while (cin >> temp_var){
    words.push_back(temp_var);
  }
  cout << endl << "Got the input." << endl;

  // Check to make sure there was something input before any other operations are performed
  typedef vector<string>::size_type vec_size;
  vec_size words_vec_size = words.size();
  if (words_vec_size == 0){
    cout << "\nYou didn't enter anything...";
    return 1;
  }

  // Perform operations on the input if there was input
  sort(words.begin(), words.end());
  cout << "\nThis is the alphabetically sorted input: " << endl;
  for (vec_size i = 0; i != words_vec_size; ++i){
    cout << "\t" << words[i] << endl;
  }

  // Create a vector containing the length of each word.  Note that the index for words and word sizes is identical.
  vector<int> word_sizes;
  for (vec_size i = 0; i != words_vec_size; ++i){
    word_sizes.push_back(words[i].length());
  }

  cout << "Word sizes: " << endl;
  for (vec_size i = 0; i != words_vec_size; ++i){
    cout << "\t" << word_sizes[i] << endl;
  }

  int ws_max_el = *max_element(word_sizes.begin(), word_sizes.end());
  int ws_min_el = *min_element(word_sizes.begin(), word_sizes.end());

  typedef vector<int>::size_type vector_index;
  vector_index max_index = max_element( word_sizes.begin(), word_sizes.end() ) - word_sizes.begin();
  vector_index min_index = min_element( word_sizes.begin(), word_sizes.end() ) - word_sizes.begin();

  cout << "Index of the max element: " << max_index << endl;
  cout << "Index of the min element: " << min_index << endl;

  cout << "\nThe LARGEST word input is: \"" << words[max_index] << "\"." << endl;
  cout << "The word is " << ws_max_el << " characters long." << endl;

  cout << "\nThe SMALLEST word input is: \"" << words[min_index] << "\"." << endl;
  cout << "The word is " << ws_min_el << " characters long." << endl;
  
  return 0;
}

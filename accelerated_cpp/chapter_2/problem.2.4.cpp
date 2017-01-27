/* $2.e/34
   Problem 2-4
   This program is similar to Problem 2-3 except it prints the whitespace characters needed for a line in a single statement (rather than 1 character at a time).
*/

#include <iostream>
#include <string>

// say what standard-library names we want to use
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  // ask for the person's name
  cout << "Please enter your name: ";

  // read the name
  string name;
  cin >> name;

  // build the message that we intend to write
  const string greeting = "Hello, " + name + "!";
  
  // the number of blanks surrounding the greeting
  cout << "\nEnter the vertical and horizontal padding separated by a space: ";
  int pad_r;
  int pad_c;
  cin >> pad_r;
  cin >> pad_c;

  // calculate the number of rows and columns to write
  const int rows = pad_r * 2 + 3;
  const string::size_type cols = greeting.size() + pad_c * 2 + 2;

  // write a blank line to separate the output from the input
  cout << endl;

  // write 'rows' rows of output
  string line = "";
  string padding_string = "";

  for (int r = 0; r != rows; ++r){
    if (r == 0 || r == rows - 1){
      line.assign(2*pad_c + greeting.size() + 2, '*');
    }else if (r == pad_r + 1){
      padding_string.assign(pad_c, ' ');
      line = line + "*" + padding_string + greeting + padding_string + "*";
    }else{
      padding_string.assign(2*pad_c + greeting.size(), ' ');
      line = line + "*" + padding_string + "*";
    }
      cout << line << "\n";
      line.clear();
  }
  return 0;
}

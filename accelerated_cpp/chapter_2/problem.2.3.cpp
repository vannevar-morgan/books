/* $2.e/34
   Problem 2-3
   This program is similar to Problem 2-2 except it asks the user for the spacing of row and column padding.
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
  uint pad_r;
  uint pad_c;
  cin >> pad_r;
  if(pad_r > 50){
    cout << "Sorry, padding must be in range [0, 30]..." << endl;
    cout << "Vertical padding is set to 0..." << endl;
    pad_r = 0;
  }
  cin >> pad_c;
  if(pad_c > 50){
    cout << "Sorry, padding must be in range [0, 30]..." << endl;
    cout << "Horizontal padding is set to 0..." << endl;
    pad_c = 0;
  }


  // calculate the number of rows and columns to write
  const string::size_type rows = pad_r * 2 + 3;
  const string::size_type cols = greeting.size() + pad_c * 2 + 2;

  // write a blank line to separate the output from the input
  cout << endl;

  // write 'rows' rows of output
  // invariant: we have written 'r' rows so far
  for (string::size_type r = 0; r != rows; ++r){
      string::size_type c = 0;

      // invariant: we have written c characters so far in the current row
      while (c != cols){
	  // is it time to write the greeting?
	  if (r == pad_r + 1 && c == pad_c + 1){
	      cout << greeting;
	      c += greeting.size();
	    }else{
	    
	    // are we on the border?
	    if (r == 0 || r == rows - 1 ||
		c == 0 || c == cols - 1)
	      cout << "*";
	    else
	      cout << " ";

	    ++c;
	  }
      }
      cout << endl;
  }
  return 0;
}

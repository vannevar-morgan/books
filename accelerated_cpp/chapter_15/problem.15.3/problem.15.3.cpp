#include <iostream>
#include <string>
#include <vector>
#include "Picture.hpp"



using namespace std;

int main(void){
  cout << "Enter some text to frame:\n";
  vector<string> text;
  string temp;
  while(getline(cin, temp)){
    text.push_back(temp);
  }

  Picture p(text);
  cout << "\nThis is the string picture:\n";
  cout << p;
  cout << "\nThis is the (default) framed picture:\n";
  Picture f = frame(p);
  cout << f << endl;
  cout << "\nThis is the horizontally concatenated (framed, plainstring) picture:\n";
  cout << hcat(f, p) << endl;
  cout << "\nThis is the horizontally concatenated (plainstring, framed) picture:\n";
  cout << hcat(p, f) << endl;
  cout << "\nThis is the vertically concatenated (framed, plainstring) picture:\n";
  cout << vcat(f, p) << endl;
  cout << "\nThis is the vertically concatenated (plainstring, framed) picture:\n";
  cout << vcat(p, f) << endl;

  cout << "\nThis is the multipicture (problem 15.1):\n";
  Picture q = frame(p, 'C', 'T', 'L', 'R');
  Picture r = hcat(p, q);
  Picture s = vcat(q, r);
  cout << frame(hcat(s, vcat(r, q)), '$', '#') << endl;





  return 0;
}

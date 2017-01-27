#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
  cout << "\nThis is the horizontally concatenated (plainstring small, plainstring big) w / even sz_diff picture:\n";
  text.push_back("hello");
  text.push_back("hello");
  Picture p2(text);
  cout << hcat(p, p2);
  cout << "\nThis is the horizontally concatenated (plainstring small, plainstring big) w / odd sz_diff picture:\n";
  text.push_back("hello");
  Picture p3(text);
  cout << hcat(p, p3);
  cout << "\nThis is the horizontally concatenated (plainstring big, plainstring small) w / even sz_diff picture:\n";
  cout << hcat(p2, p);
  cout << "\nThis is the horizontally concatenated (plainstring big, plainstring small) w / odd sz_diff picture:\n";
  cout << hcat(p3, p);
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
  Picture t = frame(hcat(s, vcat(r, q)), '$', '#');
  cout << t << endl;

  cout << "\nReframing the multipicture (problem 15.4):\n";
  queue<char> new_chars({'@', '@', '@', '@', ',', ',', ',', ',', '^', '%', '!', '#', ' ', 'W', 'W', 'W', ' ', 'Q', 'Q', 'Q', '_', '+'});
  // other sets of framing characters to test with...
  //  queue<char> new_chars({'@', '@', '@', '@', ',', ',', ',', ',', '!', '#'});
  //  queue<char> new_chars({'@', '^'});
  Picture w = t;
  reframe(t, new_chars);
  cout << t << endl;
  cout << "\nOriginal multipicture (should be unchanged):\n";
  cout << w << endl;





  return 0;
}

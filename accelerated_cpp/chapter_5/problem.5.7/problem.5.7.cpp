#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);

int main()
{
  vector<string> v;
  // frame(v);  // as given in problem statement for problem 5.7
  v = frame(v);  // as i think problem 5.7 is meant to be run
  
  // print framed text
  for(const string& s : v){
    cout << s << endl;
  }

  return 0;
}


string::size_type width(const vector<string>& v)
{
  //
  // Return the length of the longest string in v.
  //
  string::size_type maxlen = 0;
  for(vector<string>::size_type i = 0; i != v.size(); ++i){
    maxlen = max(maxlen, v[i].size());
  }
  return maxlen; // maxlen == 0 if v is an empty vector
}


vector<string> frame(const vector<string>& v)
{
  //
  // Frame the text picture with an asterisk border.
  //
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');
  
  // write the top border
  ret.push_back(border);
  
  // write each interior row, bordered by an asterisk and a space
  for(vector<string>::size_type i = 0; i != v.size(); ++i){
    ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
  }
  
  // write the bottom border
  ret.push_back(border);
  return ret;
}

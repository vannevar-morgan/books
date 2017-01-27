#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


string::size_type width(const vector<string>& v);
vector<string> frame(const vector<string>& v);
vector<string> hcat(const vector<string>& left, const vector<string>& right);

int main(){
  cout << "enter some text to frame: " << endl;
  string s;
  vector<string> text;
  while(getline(cin, s)){
    text.push_back(s);
  }
  
  // test frame()
  vector<string> framed_text = frame(text);

  cout << endl;
  for(auto t : framed_text){
    cout << t << endl;
  }
  cout << endl;
  
  // test hcat()
  text = hcat(text, framed_text);
  cout << endl;
  for(auto t : text){
    cout << t << endl;
  }
  cout << endl;
  
  
  return 0;
}


string::size_type width(const vector<string>& v){
  //
  // Returns the length of the longest string in vector v.
  //
  vector<string>::const_iterator c_iter;
  string::size_type maxlen = 0;
  for(c_iter = v.begin(); c_iter != v.end(); ++c_iter){
    maxlen = max(maxlen, c_iter->size());
  }
  
  return maxlen;
}


vector<string> frame(const vector<string>& v){
  //
  // Frame the text in vector v with '*' symbols.
  //
  vector<string> ret;
  string::size_type maxlen = width(v);
  string border(maxlen + 4, '*');
  
  // write the top border
  ret.push_back(border);
  
  // write each interior row, bordered by an asterisk and a space
  vector<string>::const_iterator c_iter;
  for(c_iter = v.begin(); c_iter != v.end(); ++c_iter){
    ret.push_back("* " + *c_iter + string(maxlen - c_iter->size(), ' ') + " *");
  }
  
  // write the bottom border
  ret.push_back(border);
  
  return ret;
}


vector<string> hcat(const vector<string>& left, const vector<string>& right){
  //
  // Horizontally concatenates two text pictures.
  //
  vector<string> ret;
  
  // add 1 to leave a space between pictures
  string::size_type width1 = width(left) + 1;
  
  // indices to look at elements from left and right respectively
  vector<string>::const_iterator l_iter = left.begin(), r_iter = right.begin();
  
  // continue until we've seen all rows from both pictures
  while(l_iter != left.end() || r_iter != right.end()){
    // construct new string to hold characters from both pictures
    string s;
    
    // copy a row from the left-hand side, if there is one
    if(l_iter != left.end()){
      s = *l_iter++;
    }
    
    // pad to full width
    s += string(width1 - s.size(), ' ');
    
    // copy a row from the right-hand side, if there is one
    if(r_iter != right.end()){
      s += *r_iter++;
    }
    
    // add s to the picture we're creating
    ret.push_back(s);
  }
  
  return ret;
}

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::isupper;
using std::isspace;
//using std::getline;

// void get_input(vector<string>& lines)
// {
//   string s;
//   while (getline(cin, s)) {
//     lines.push_back(s);
//   }
// }

vector<string> split(const string& s)
{
  vector<string> v;
  typedef string::size_type str_sz;
  str_sz i = 0;

  while ( i != s.size() ) {
    while ( i != s.size() && isspace(s[i]) ) {
      ++i;
    }
    
    str_sz j = i;
    while ( j != s.size() && !isspace(s[j]) ) {
      ++j;
    }
    
    if (i != j) {
      v.push_back(s.substr(i, j - i));
      i = j;
    }

  }
  return v;
}

void classify_caps(const vector<string> words, vector<string>& ucase, vector<string>& lcase)
{
  vector<string>::const_iterator iter = words.begin();

  while ( iter != words.end() ) {
    string::size_type word_length = (*iter).size();
    string::size_type a = 0;
    bool upper = false;
    while ( a != word_length ) {
      if ( isupper((*iter)[a]) ) {
	ucase.push_back(*iter);
	upper = true;
	break;
      }
      ++a;
    }
    if (!upper) {
      lcase.push_back(*iter);
    }
    ++iter;
  }

}

int main()
{
  string s;
  vector<string> ucase_words, lcase_words;
  cout << "enter some words:" << endl;
  while (getline(cin, s)) {
    vector<string> words = split(s);
    classify_caps(words, ucase_words, lcase_words);
  }

  cout << "\nWords without uppercase letters..." << endl;
  vector<string>::const_iterator iter = lcase_words.begin();
  while ( iter != lcase_words.end() ) {
    cout << *iter << endl;
    ++iter;
  }
  cout << "\nWords with an uppercase letter..." << endl;
  iter = ucase_words.begin();
  while ( iter != ucase_words.end() ) {
    cout << *iter << endl;
    ++iter;
  }
  
  return 0;
  
}

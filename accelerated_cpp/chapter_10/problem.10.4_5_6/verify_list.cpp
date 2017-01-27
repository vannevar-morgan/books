#include "StringList.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;


int main(){
  // test push_back()
  // get some words from the user to add to the list
  cout << "Testing push_back()..." << endl;
  cout << "Enter some words to test the list:" << endl;
  string s;
  StringList slist;
  while(cin >> s){
    slist.push_back(s);
  }

  // echo the list elements back to verify they are correctly contained in the list
  cout << "\nThese are the words you entered:" << endl;
  for(const string& w : slist){
    cout << w << endl;
  }

  // verify front() and back() work
  cout << "\nTesting front() and back()..." << endl;
  try{
    cout << "First element in list: " << slist.front() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  try{
    cout << "Last element in list: " << slist.back() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }

  // verify begin() and end() work
  cout << "\nThese are the list elements printed using begin() and end()..." << endl;
  auto beg_iter = slist.begin();
  auto end_iter = slist.end();
  while(beg_iter != end_iter){
    cout << *beg_iter << endl;
    ++beg_iter;
  }

  // test write-access using the non-const version of the StringList::iterator
  cout << "\nTesting writing the value pointed by a (non-const) list iterator (first element will be written as 'hello')..." << endl;
  try{
    if(slist.empty()){
      cout << "list is empty so the iterator returned by list.begin() cannot be dereferenced to assign the value 'hello'..." << endl;      
    }else{
      beg_iter = slist.begin();
      *beg_iter = "hello";
      cout << "Wrote first element as 'hello'..." << endl;
    }
  }catch(const exception& e){
    cout << "couldn't write using slist.begin()..." << endl;
  }
  cout << "\nThese are the list elements printed using begin() and end()..." << endl;
  beg_iter = slist.begin();
  end_iter = slist.end();
  while(beg_iter != end_iter){
    cout << *beg_iter << endl;
    ++beg_iter;
  }


  // verify size() works
  cout << "\nSize of list: " << slist.size() << endl;

  // verify empty() works
  cout << "Testing empty()..." << endl;
  cout << "Is list empty? (compare to size above): ";
  if(slist.empty()){
    cout << "list is empty..." << endl;
  }else{
    cout << "list is NOT empty..." << endl;
  }

  // verify clear() works
  cout << "Testing clear()..." << endl;
  slist.clear();
  cout << "Size of list: " << slist.size() << endl;
  cout << "Is list empty? (it should be empty): ";
  if(slist.empty()){
    cout << "list is empty..." << endl;
  }else{
    cout << "ERROR: list.empty() returns false after call to list.clear() (list should be empty)..." << endl;
  }

  cout << "Testing front() and back() on an empty list (both should raise exceptions)..." << endl;
  try{
    cout << "First element in list: " << slist.front() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  try{
    cout << "Last element in list: " << slist.back() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }

  // test push_front()
  // get some words from the user to add to the list
  cin.clear(); // reset cin
  cout << "\nTesting push_front()..." << endl;
  cout << "Enter some words to test the list:" << endl;
  while(cin >> s){
    slist.push_front(s);
  }

  // echo the list elements back to verify they are correctly contained in the list
  cout << "\nThese are the words you entered (in reverse order because push_front was used):" << endl;
  for(const string& w : slist){
    cout << w << endl;
  }

  // test other functions again after push_front()
  cout << "\nSize of list: " << slist.size() << endl;
  cout << "Is list empty? (compare to size above): ";
  if(slist.empty()){
    cout << "list is empty..." << endl;
  }else{
    cout << "list is NOT empty..." << endl;
  }

  cout << "Testing front() and back()..." << endl;
  try{
    cout << "First element in list: " << slist.front() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  try{
    cout << "Last element in list: " << slist.back() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }

  // test pop_front() and pop_back()
  cout << "\nTesting pop_front()..." << endl;
  try{
    slist.pop_front();
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  cout << "These are the list elements after pop_front() is called:" << endl;
  for(const string& w : slist){
    cout << w << endl;
  }
  cout << "\nTesting pop_back()..." << endl;
  try{
    slist.pop_back();
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  cout << "These are the list elements after pop_back() is called:" << endl;
  for(const string& w : slist){
    cout << w << endl;
  }

  // test other functions again after pop_front() and pop_back()
  cout << "\nSize of list: " << slist.size() << endl;
  cout << "Is list empty? (compare to size above): ";
  if(slist.empty()){
    cout << "list is empty..." << endl;
  }else{
    cout << "list is NOT empty..." << endl;
  }

  cout << "Testing front() and back()..." << endl;
  try{
    cout << "First element in list: " << slist.front() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  try{
    cout << "Last element in list: " << slist.back() << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }

  // test const versions of begin() and end()
  cout << "\nTesting const versions of begin() and end()..." << endl;
  StringList::const_iterator c_beg_iter = slist.begin();
  StringList::const_iterator c_end_iter = slist.end();

  cout << "These are the list elements printed using const versions of begin() and end()..." << endl;
  while(c_beg_iter != c_end_iter){
    cout << *c_beg_iter << endl;
    ++c_beg_iter;
  }

  // test const versions of front() and back()
  cout << "\nTesting const versions of front() and back()..." << endl;
  try{
    StringList::const_reference front = slist.front();
    cout << "First element in list: " << front << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }
  try{
    StringList::const_reference back = slist.back();
    cout << "Last element in list: " << back << endl;
  }catch(const out_of_range& oor){
    cout << "Out of Range error: " << oor.what() << endl;
  }



  cout << endl;

  return 0;
}

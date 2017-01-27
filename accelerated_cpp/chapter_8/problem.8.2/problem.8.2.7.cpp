// implements the "search()" algorithm.
// requires 4 input iterators.
#include <vector>
#include <iostream>
#include <string>
#include <iterator>


template <class In>
In search(In beg, In end, In beg2, In end2)
{
  if(beg2 == end2){
    // per c++98 if [beg2, end2) is an empty range the result is undefined.
    // per c++11 if [beg2, end2) is an empty range the result is beg.
    return beg;
  }

  if((end - beg) < (end2 - beg2)){
    // if the length of the sequence [beg, end) is less than the length of [beg2, end2) then the sequence [beg2, end2) can't exist in [beg, end).
    return end;
  }

  In beg2_orig = beg2;
  In beg_temp = beg;
  while(beg != end){
    // find the beginning of the first possible sequence [beg2, end2) in [beg, end)
    while(*beg != *beg2 && beg != end){
      ++beg;
    }
    beg_temp = beg;
    // increment beg and beg2 until the end of [beg, end) is reached, or until the end of [beg2, end2) is reached, while *beg == *beg2
    while(beg != end && beg2 != end2 && *beg++ == *beg2++){}
    // if beg2 == end2 then the entire subrange [beg2, end2) exists in [beg, end)
    if(beg2 == end2){
      // return an iterator to the start of subrange [beg2, end2) in [beg, end)
      return beg_temp;
    }
    // otherwise, reset beg2 and continue
    beg2 = beg2_orig;
  }
  return end;
}


int main()
{
  std::cout << "Testing the implementation of the search() library algorithm...\n" << std::endl;
  int n;
  std::vector<int> seq1;
  std::vector<int> seq2;

  // get some data from the user to act on as the first sequence
  std::cout << "Enter some integers: \n";
  while(std::cin >> n){
    seq1.push_back(n);
  }

  // reset std::cin
  if(!std::cin){
    std::cout << "(press enter)\n";
    std::cin.clear();
    std::string s;
    std::getline(std::cin, s);
  }

  // get some data from the user to act on as the second sequence
  std::cout << "Enter some integers: \n";
  while(std::cin >> n){
    seq2.push_back(n);
  }

  // search over seq1 to find seq2
  std::vector<int>::const_iterator seq2_beginning = search(seq1.begin(), seq1.end(), seq2.begin(), seq2.end());

  // echo results to user
  if(seq2_beginning != seq1.end()){
    std::cout << "The second sequence is contained in the first.\n";
    // highlight the second sequence within the 1st sequence
    std::vector<int>::const_iterator iter = seq1.begin();
    while(iter != seq2_beginning){
      std::cout << *iter++ << " ";
    }
    std::cout << " << ";
    for(; iter != seq2_beginning + seq2.size(); ++iter){
      std::cout << *iter << " ";
    }
    std::cout << " >> ";
    while(iter != seq1.end()){
      std::cout << *iter++ << " ";
    }
    std::cout << std::endl;
  }else{
    if(seq1.size() == 0 && seq2.size() == 0){
      std::cout << "You entered two empty sequences..." << std::endl;
    }else{
      std::cout << "The second sequence is NOT contained in the first.\n";
    }
  }


  return 0;
}

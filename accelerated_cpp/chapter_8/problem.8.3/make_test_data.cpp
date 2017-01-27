#include <iostream>
#include <random>
#include <unistd.h>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

/*
 * Create a dataset of ints or string to test with.
 *
 * An int dataset will be created with ints in range [-50, 49]
 *
 * A string dataset will be created with string of length 6, 
 * composed of random uppercase English letters.
 */

void make_data_int(int elements, string out_filename);
void make_data_string(int elements, string out_filename);

int main(int argc, char* argv[]){
  if(argc != 3 && argc != 4){
    cout << "usage: ./makeTD num_elements=10 file_name=test.data data_type=[1,2](int/string)" << endl;
    return -1;
  }
  srand(time(0) ^ getpid()); // init prng
  int n = 10;
  n = atoi(argv[1]);
  string out_filename = "test.data";
  if(argc == 3){
    out_filename = string(argv[2]);
  }
  int data_type = 1;
  if(argc == 4){
    data_type = atoi(argv[3]);
  }
  
  if(data_type == 1){
    make_data_int(n, out_filename);
  }else if(data_type == 2){
    make_data_string(n, out_filename);
  }
  
  return 0;
}


void make_data_int(int elements, string out_filename){
  //
  // Write a dataset of "elements" number of elements
  // of type int, to the specified dataset file.
  //
  ofstream outFile(out_filename.c_str());
  for(int i = 0; i < elements; ++i){
    outFile << (rand() % 100) - 50 << endl;
  }
  outFile.close();
}

void make_data_string(int elements, string out_filename){
  //
  // Write a dataset of "elements" number of elements
  // of type string, to the specified dataset file.
  //
  ofstream outFile(out_filename.c_str());
  for(int i = 0; i < elements; ++i){
    for(int j = 0; j < 6; ++j){
      outFile << (char)((rand() % 26) + 65);
    }
    outFile << endl;
  }
  outFile.close();
}

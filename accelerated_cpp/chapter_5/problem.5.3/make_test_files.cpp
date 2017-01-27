#include <iostream>
#include <fstream>
#include <random>
#include <unistd.h>
#include <ctime>

using namespace std;

//void make_test_file(const int lines, const string& filename);
class namelist{
public:
  std::string getName() const { return m_names[ rand() % m_names.size()]; }
    
private:
  const vector<string> m_names = {"yuri",
				  "vivian",
				  "andrew",
				  "donald",
				  "anna",
				  "carl",
				  "michelle",
				  "richard",
				  "horace",
				  "virginia"};
};

void make_test_file(const int num_homeworks, const int lines, const string& filename, const namelist& n);


int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "usage: ./make_test_files #homeworks #lines1 #lines2 ..." << endl;
    return -1;
  }
  
  // init prng for naming students
  srand(time(0) ^ getpid());
  
  int lines;
  namelist n;
  int n_homeworks = atoi(argv[1]);
  string filename = "test_file_";
  
  for(int i = 2; i < argc; ++i){
    lines = atoi(argv[i]);
    make_test_file(n_homeworks, lines, filename + string(argv[i]) + ".txt", n);
  }
  
  return 0;
}


void make_test_file(const int num_homeworks, const int lines, const string& filename, const namelist& n){
  ofstream file_out(filename.c_str());
  for(int i = 0; i < lines; ++i){
    // write the student name and the midterm and final exam grades
    file_out << n.getName() << " " << rand() % 101 << " " << rand() % 101;
    // write the homework grades
    for(int j = 0; j < num_homeworks; ++j){
      file_out << " " << rand() % 101;
    }
    file_out << endl;
  }
  
  file_out.close();
}



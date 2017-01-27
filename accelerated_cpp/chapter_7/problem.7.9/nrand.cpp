#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include "nrand.h"


// return a random integer in the range [0, n)
int nrand(int n)
{
  const int TEST_RAND_MAX = 32767;

  if(n <= 0){
    throw std::domain_error("Argument to nrand is out of range");
  }
  // calculate the number of repetitions we need to do (with bucket_size = 1)
  const int reps = std::ceil((double) n / TEST_RAND_MAX);

  // sum buckets for the first (reps - 1) repetitions
  int sum_rand = 0;
  for(int i = reps; i > 1; --i){
    sum_rand += test_rand(TEST_RAND_MAX); // bucket size is 1 when n > rand_max
  }

  // sum the final bucket
  const int REM_N = n - (TEST_RAND_MAX * (reps - 1)); // calculate remaining n in this repetition
  const int bucket_size = TEST_RAND_MAX / REM_N;
  int r;

  do r = test_rand(TEST_RAND_MAX) / bucket_size;
  while(r >= REM_N);

  sum_rand += r;

  return sum_rand;
}


// Because rand() returns a pseudorandom integer in the range [0, RAND_MAX] (RAND_MAX = 2147483647 on my system),
// to test the program we need a function which returns numbers in the range [0, TEST_RAND_MAX].
int test_rand(int n){
  // return rand() % (n + 1);
  return ((double)(n + 1)*rand()/(RAND_MAX + 1.0));
  // see https://groups.google.com/forum/#!topic/gnu.gcc/U3QXY9GW_LU
}

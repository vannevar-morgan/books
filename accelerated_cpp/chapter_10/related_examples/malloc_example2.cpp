/* malloc example: random string generator*/
#include <iostream>
#include <cstdio> // for printf
#include <cstdlib> // for srand, rand, malloc

int main()
{
  printf("How long should the string be: ");
  int n;
  std::cin >> n;

  char* p = (char*) malloc(n + 1); // add 1 for the null character

  // initialize rand()
  srand(time(0));

  // create the random string
  int i = 0;
  while(i < n){
    p[i++] = rand()%26 + 'a';
  }
  p[i] = '\0';

  // print the random string
  printf("random string: %s\n", p);

  /*
  char* q = p;
  while(*q != '\0'){
    std::cout << *q++;
  }
  std::cout << std::endl;
  */

  // free the allocated memory pointed at by p
  free(p);
  
  return 0;
}

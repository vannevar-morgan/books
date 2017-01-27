#include <iostream>
#include <string>

int main()
{
  std::cout << "What is your name? ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name
	    << std::endl << "And what is yours? ";
  std::cin >> name;
  std::cout << "Hello, " << name
	    << "; nice to meet you too!" << std::endl;

  return 0;
}

//
// Program prompts for a name, then prints a personalized greeting, prompts for a second name, prints another personalized greeting.
//
// If you enter two names i.e., "Samuel Beckett" on the first prompt then it will read in the first name and print the first personalized greeting, and without pause will read in the second name, print the second personalized greeting, and terminate.
//

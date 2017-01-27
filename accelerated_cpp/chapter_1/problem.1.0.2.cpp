#include <iostream>
#include <string>

int main()
{
  std::cout << "Please enter your name: ";
  std::string name;
  std::cin >> name;

  // build the message before writing it
  const std::string greeting = "Hello, " + name + "!";
  
  // build the 2nd and fourth lines fo the output
  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";

  // build the 1st and 5th lines of the output
  const std::string first(second.size(), '*');

  // write the output
  std::cout << std::endl;
  std::cout << first << std::endl;
  std::cout << second << std::endl;
  std::cout << "* " << greeting << " *" << std::endl;
  std::cout << second << std::endl;
  std::cout << first << std::endl;

  return 0;
}

// Learning c++ 

#include <iostream>

int main() {
  int val1;
  int val2;

  std::string stop;

  while(stop !=  "|"){

    std::cout << "Enter two numerical vales: \n";
    std::cin >> val1 >> val2;

    std::cout << val1 << " and " << val2 <<  "\n";

    std::cout << "Again? Enter | for not: ";
    std::cin >> stop;
   
    
  }
 

  std::cout << "Done";
}
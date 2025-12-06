// Augment the program so that it writes the line “the numbers are equal
//  only if the two numbers are equal.

//  Change the program to write out  
// the smaller value is: followed by the smaller of the numbers  
// the larger value is: followed by the larger value.
// Learning c++ 

#include <iostream>

int main() {
  int val1;
  int val2;

  std::string stop;

  while(stop !=  "|"){

    std::cout << "Enter two numerical vales: \n";
    std::cin >> val1 >> val2;

   // Logic to determine and print smaller and larger values
    if(val1 > val2){
      std::cout << "the smaller  value is: " << val2;
    }
    else if(val1 < val2){
      std::cout << "the larger value is: "  << val2;
    }
    else{
      std::cout << "The numbers are equal";
    }

    std::cout << " \n Again? Enter | for not: \n ";
    std::cin >> stop;
   
  }
 

  std::cout << "Done";
}
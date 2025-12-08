
 // Change the program so that it writes out 
 // **“the numbers are almost equal”** 
 // after writing out which is the larger and the smaller if the two numbers differ by less than `1.0/100`.


#include <iostream>

int main() {
  double val1;
  double val2;

  std::string stop;

  while(stop !=  "|"){

    std::cout << "Enter two numerical vales: \n";
    std::cin >> val1 >> val2;

   // Logic to determine and print smaller and larger values

    if(val1 - val2 < 1.0/100 && val2 - val1 < 1.0/100){
      std::cout << "The numbers are almost equal";
    }
    else if(val1 > val2){
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
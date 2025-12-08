/*Modify the loop so that it reads **one `double`** each time.  
Define two variables to keep track of the smallest and largest values seen so far.  
Each time through the loop, write out the value entered.  
- If it’s the smallest so far, write **“the smallest so far”**  
- If it’s the largest so far, write **“the largest so far”**  
*/

#include <iostream>

int main() {
  double smallest = 1.001;
  double largest = 1.4;

  double comparedValued;

  std::string stop = " ";

  // Enter the value that will be compared
  std::cout << "Enter one value: \n";
  std::cin >> comparedValued;



  while(stop !=  "|"){

    std::cout << "The value that you entered is: " << comparedValued <<"\n";

    if((comparedValued) > largest){
      std::cout << "the larger so far is "  << comparedValued;

      largest = comparedValued;
    }

    else if(comparedValued < smallest){

      std::cout << "the smallest so far is: " << comparedValued << "\n";

      smallest = comparedValued;
    }
    
    else{
      std::cout << "The number is between the largest and smallest: " << comparedValued;
    }

    std::cout << " \n Again? Enter | for not: \n ";
    std::cin >> stop;

    // Enter the value that will be compared
    std::cout << "Enter one value: \n";
    std::cin >> comparedValued;
   
  }
 

  std::cout << "Done";
}
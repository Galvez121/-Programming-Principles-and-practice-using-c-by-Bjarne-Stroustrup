/*Add a unit to each `double` entered. Input examples:  
`10cm`, `2.5in`, `5ft`, `3.33m`.  

Accept the four units: `cm`, `m`, `in`, `ft`.  
Assume these conversions:  
- `1m = 100cm`  
- `1in = 2.54cm`  
- `1ft = 12in`

Read the unit into a string.  
Values such as `12 m` (with space) may be considered equivalent to `12m`. 
*/

#include <iostream>

void comparationNumber(double& smallest, double& largest){
  double comparedValue;
    
  // Enter the value that will be compared
  std::cout << "Enter one value: \n";
  std::cin >> comparedValue;



  std::cout << "The value that you entered is: " << comparedValue
 <<"\n";

    if((comparedValue
) > largest){
      std::cout << "the larger so far is "  << comparedValue
  ;

      largest = comparedValue
  ;
    }

    else if(comparedValue
   < smallest){

      std::cout << "the smallest so far is: " << comparedValue
   << "\n";

      smallest = comparedValue
  ;
    }
    
    else{
      std::cout << "The number is between the largest and smallest: " << comparedValue
  ;
    }

  }

int main() {

  double smallest = 1.001;
  double largest = 1.4;

  double comparedValue;

  std::string unit = "";

  std::string stop = " ";



  while(stop !=  "|"){

    comparationNumber(smallest, largest);

    std::cout << " \n Again? Enter | for not: \n ";
    std::cin >> stop;

  }
 

  std::cout << "Done";
}
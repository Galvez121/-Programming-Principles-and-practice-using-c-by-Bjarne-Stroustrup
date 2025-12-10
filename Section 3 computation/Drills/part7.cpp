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

  std::string unit = "";
    
  // Enter the value that will be compared
  std::cout << "Enter one value and its unit (ex: 10cm, 1.5in): \n";
  std::cin >> comparedValue >> unit;

  // Convert the value to meters
    double valueInMeters = 0.0;
    if (unit == "m") {
        valueInMeters = comparedValue;
    } else if (unit == "cm") {
        valueInMeters = comparedValue / 100.0; // 100 cm = 1 m
    } else if (unit == "in") {
        valueInMeters = comparedValue * 2.54 / 100.0; // 1 in = 2.54 cm
    } else if (unit == "ft") {
        valueInMeters = comparedValue * 12.0 * 2.54 / 100.0; // 1 ft = 12 in
    } else {
        std::cout << "Invalid unit. Please use cm, m, in, or ft.\n";
        return; // Exit the function if the unit is invalid
    }

    std::cout << "The value in meters is: " << valueInMeters << " m\n";

    // Compare the value in meters
    if (valueInMeters > largest) {
        std::cout << "The largest so far is: " << valueInMeters << " m\n";
        largest = valueInMeters;
    } else if (valueInMeters < smallest) {
        std::cout << "The smallest so far is: " << valueInMeters << " m\n";
        smallest = valueInMeters;
    } else {
        std::cout << "The number is between the largest and smallest: " << valueInMeters << " m\n";
    }

  }

int main() {

  double smallest = 1.001;
  double largest = 1.4;

  double comparedValue;

  std::string stop = " ";



  while(stop !=  "|"){

    comparationNumber(smallest, largest);

    std::cout << " \n Again? Enter | for not: \n ";
    std::cin >> stop;

  }
 

  std::cout << "Done";
}
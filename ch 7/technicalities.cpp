#include <iostream>

// pass-by-value vs Pass-by-reference  vs pass-by-const-reference

void g(int a, int& r, const int& cr){
    ++a;        // change the loca a
    ++r;        // change the object referred to by r
    int x = cr; // read the object referred to by cr
}

int main(){
    int x = 0;
    int y = 0;
    int z = 0;

    g(x,y,z); // x == 0; y == 1; z == 0
   // g(1,2,3); // error: reference argument r needs a variable to refer to
    g(1,y,3);  // here: OK, since cr is const we can pass a litera;
            /*means: int compiler_generated = 3; g(1,y, compiler_generated)*/
}
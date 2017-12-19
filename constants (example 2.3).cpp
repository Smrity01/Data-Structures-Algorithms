/* This program will demonstrates three ways to use constants
   written by: Smrity Chaudhary
   Date : 19-12-2017
*/
#include<iostream>
using namespace std;

#define PI 3.1415926536

int main(){
const double pi = 3.1415926536;
/*
defined constants: The constant(3.14..) replaces the its name(PI) wherever it is found in the source code.
memory constants : Its use 'const' quantifier  to indicate that the data cannot be changed.
literal constants: It is a unnamed constant used to specify data.
*/
cout << "Defined constant PI: " << PI << '\n';
cout << "Memory constant pi: " << pi << '\n';
cout << "Literal constant: " << 3.1415926536 << '\n';
return 0;
}



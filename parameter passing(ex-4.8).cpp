/*Divide two numbers return quotient and remainder using pass by reference
   written by: Smrity chaudhary
   Date : 22-12-17
*/
#include<iostream>
using namespace std;
//Prototype declaration
void divide(int,int,int&,int&);

int main(){
  int divisor;
  int dividend;
  cout << "Enter dividend: ";
  cin >> dividend;
  cout << "Enter divisor: ";
  cin >> divisor;
  int quotient;
  int remainder;
  divide(dividend,divisor,quotient,remainder);
  cout << "\n\n...........Reflect the changes in MAIN because parameters are passed by reference...............  ";
  cout << "\n\nSolve the problem of return two values...\n\n";
  cout << "\nQuotient is: " << quotient;
  cout << "\nRemainder is: " << remainder;
  return 0;
}
// Divide two numbers
void divide(int dvnd, int dvsr,int& quo,int& rem){
  quo = dvnd / dvsr;
  rem = dvnd % dvsr;
  return ;
}

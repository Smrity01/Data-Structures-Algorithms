/* Demonstrate the use of numeric manipulators
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int int_var = 123;

  cout << "____Demonstrate use of numeric manipulators____ \n";
  cout << "Decimal    : " << int_var << '\n';
  cout << "Hexadecimal: " << hex << int_var << '\n';
  cout << "octal      : " << oct <<int_var << '\n';
  cout << " size of null: " << sizeof('\0') << '\0' << '\n';
  cout << "size of empty string: " << sizeof("") << "" <<'\n';
return 0;
}

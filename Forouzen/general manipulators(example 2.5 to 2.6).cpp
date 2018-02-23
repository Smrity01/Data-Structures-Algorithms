/* Demonstrate the use of set width and fill character
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  int int_var = 123;
  float float_var = 1.23;
  char  char_var = 'A';
  cout << "____Demonstrating the use of set width____ \n";
  cout << "no width: " << int_var << float_var << char_var << '\n';
  cout << "set width 1: " << setw(1) << int_var << setw(1) << float_var << setw(1) << char_var << '\n';
  cout << "set width 5: " << setw(5) << int_var << setw(5) << float_var << setw(5) << char_var << '\n';
  cout << "string with set width 10: " << setw(10) << "Hello" << '\n';
  cout << "string with set width 3: " << setw(3) << "Hello" << '\n';
  cout << "\n ____Demonstrating the use of fill character____ \n";
  cout << " fill with  * : " << setw(10) << setfill('*') << float_var <<'\n';
  cout << " fill with  space with setfill: " << setw(10) << setfill(' ') << float_var << '\n';
  cout << " fill with  space without setfill: " << setw(10) << float_var ;
  return 0;
}

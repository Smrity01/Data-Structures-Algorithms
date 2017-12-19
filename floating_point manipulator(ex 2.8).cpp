/* Demonstrate the use of floating point manipulators
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  float float_var = 123.0;
  float float_var2 = 4122453.4827920;
  float float_var3 = 1.89273;

  cout << "____No manipulators____ \n";
  cout << float_var << '\t' << float_var2 << '\t' << float_var3 << '\n';
  cout << "\n____Fixed manipulator____ \n";
  cout << fixed << float_var << '\t' << float_var2 << '\t' << float_var3 << '\n';
  cout << "\n____set precision(2) manipulator____ \n";
  cout << setprecision(2) << float_var << '\t' << float_var2 << '\t' << float_var3 << '\n';
  cout << "\n____set precision(0) manipulator____ \n";
  cout << setprecision(0) << float_var << '\t' << float_var2 << '\t' << float_var3 << '\n';
  cout << "\n____show point manipulator____ \n";
  cout << setprecision(2) << showpoint << float_var << '\t' << float_var2 << '\t' << float_var3 << '\n';
return 0;
  }

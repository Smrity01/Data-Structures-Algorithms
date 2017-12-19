/* conversion from radian to degree
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  double radian;
  const int factor = 57.295779;
  cout << "Enter the angle in radian: ";
  cin >> radian;
  double degree = radian * factor ;
  cout << radian << "\nRadian is " << degree << " degrees. ";
return 0;
}

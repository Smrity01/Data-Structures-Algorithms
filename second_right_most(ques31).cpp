/* Print the second right most digit of a number
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
using namespace std;

int main(){
  float input;
  cout << "_____Second Right most digit of an integer value____\n";
  cout << "Enter an integer: ";
  cin >> input;
  int last = static_cast<int>(input) % 10;
  int sec_right = (input - last) / 10;
  cout << "The right most digit of your number is: " << sec_right % 10 <<'\n';
return 0;
}

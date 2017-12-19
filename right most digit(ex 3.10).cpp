/* Print the right most digit of a number
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
using namespace std;

int main(){
  int input;
  float input2;
  cout << "_____Right most digit of an integer value____\n";
  cout << "Enter an integer: ";
  cin >> input;
  int right = input % 10;
  cout << "The right most digit of your number is: " << right <<'\n';
  cout << "\n____right most digit of integral portion of a float_____\n" ;
  cout << "Enter an floating point number: ";
  cin >> input2;
  int right2 = static_cast<int>(input2) % 10;
  cout << "The right most digit of your number is: " << right2 <<'\n';
return 0;
}
l

/* Print the pattern of user enter number
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
using namespace std;

int main(){
  float input;
  cout << "_____pattern of digits____\n";
  cout << "Enter an integer(0 to 32,767): ";
  cin >> input;
  int last = static_cast<int>(input) % 10;
  int last2 = (static_cast<int>(input) / 10) % 10;
  int last3 = (static_cast<int>(input) / 100 ) % 10;
  int last4 = (static_cast<int>(input) / 1000) % 10;
  int last5 = (static_cast<int>(input) / 10000) % 10;

  cout << last5 << "   " << last4 << "   " << last3 << "   " << last2 << "   "<< last <<'\n';
  cout << last4 << "   " << last3 << "   " << last2 << "   "<< last <<'\n';
  cout << last3 << "   " << last2 << "   "<< last <<'\n';
  cout << last2 << "   "<< last <<'\n';
  cout << last <<'\n';

return 0;
}

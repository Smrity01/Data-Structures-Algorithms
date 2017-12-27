/*Round off upto two decimal places
   written by: Smrity chaudhary
   Date : 27-12-17
*/
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
float round_off(float);

int main(){
  float float_num;
  cout << "\nEnter a float number: ";
  cin >> float_num;
  float_num = round_off(float_num);
  cout << "\nFloating point number after round off: " << float_num;
  return 0;
}
float round_off(float num){
  int integer;
  integer = floor(num * 100 + 0.5); // float num is converted to integer
  return (static_cast<float>(integer)/100); // integer is converted to float
}

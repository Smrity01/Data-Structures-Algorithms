/* Demonstrate the type casting 1) implicit 2) explicit
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
using namespace std;

int main(){
  char char_var = 'A';
  int int_var = 345;
  int int_char;
  double doub_var = 23.5;
  float var;
  cout << "__implicit type casting___\n ";
  cout << "character variable: " << char_var << '\n';
  int_char = char_var;
  cout << "character to integer type casting(using assgnment operator): " << int_char << '\n';
  cout << "character converted to integer(using addition operator): " << int_var + char_var << '\n';
  cout << "Character converted to float(usind addition operator): " << doub_var + char_var << '\n';
  cout << "__explicit type casting___\n ";
  var= static_cast<float> (int_var) / doub_var;
  cout << "integer to float(explicitly): "<< var <<'\n';
  return 0;
}

/* Demonstrate the character ASCII values
   written by: Smrity chaudhary
   Date : 19-12-17
*/
#include<iostream>
using namespace std;

int main(){
  char A = 'A';
  char B = 'B';
  char a = 'a';
  char b = 'b';
  char Z = 'Z';
  char z = 'z';
  char zero = '0';
  char eight = '8';
  char NL = '\n';   //newline
  char HT = '\t';   // Horizontal tab
  char Vt = '\v';   // vertical tab
  char SP = ' ';    // space
  char BEL = '\a';  // alert bell
  char dbl = '"';   // double quote
  char backslash = '\\'; // back slash
  char onequote = '\''; // single quote

  cout << "__Ascii values of characters__\n";
  cout << "ascii value of A: " << (int)A << '\n';
  cout << "ascii value of B: " << (int)B << '\n';
  cout << "ascii value of a: " << (int)a << '\n';
  cout << "ascii value of b: " << (int)b << '\n';
  cout << "ascii value of Z: " << (int)Z << '\n';
  cout << "ascii value of z: " << (int)z << '\n';
  cout << "ascii value of 0: " << (int)zero << '\n';
  cout << "ascii value of 8: " << (int)eight << '\n';
  cout << "ascii value of '\\n': " << (int)NL << '\n';
  cout << "ascii value of '\\t': " << (int)HT << '\n';
  cout << "ascii value of '\\v': " << (int)Vt << '\n';
  cout << "ascii value of ' ': " << (int)SP << '\n';
  cout << "ascii value of '\\a': " << (int)BEL << '\n';
  cout << "ascii value of '\"': " << (int)dbl << '\n';
  cout << "ascii value of '\\': " << (int)backslash << '\n';
  cout << "ascii value of ''': " << (int)onequote << '\n';
return 0;
}

/*Demonstrate generation of random numbers in given ranges
   written by: Smrity chaudhary
   Date : 27-12-17
*/
#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main(){
  srand(997);
  // rand()%((max + 1) - min) + min
  int range1 = rand() % 5 + 3;
  cout << "range 3 to 7: " << setw(3) << range1 <<endl;
  int range2 = rand() % 31 + 20;
  cout << "range 20 to 50: " << setw(3) << range2 <<endl;
  return 0;
}

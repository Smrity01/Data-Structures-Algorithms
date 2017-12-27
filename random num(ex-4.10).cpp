/*Demonstrate srand() and rand() functions
   written by: Smrity chaudhary
   Date : 27-12-17
*/
#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
  cout << "\n_____Random numbers without seed______\n";
   "\nRemains the same on every execution...\n";
  cout << rand() << ", " << rand() << "," << rand();
  cout << "\n______Random numbers with seeds_____\n\n";
  int seed;
  cout << "\nEnter a seed: ";
  cin >> seed;
  srand(seed);
  cout << "\nRandom numbers with seed " << seed << ":" << rand() << ", " << rand() << ", " << rand();
  // print random number with another seed;
  cout << "\n\nEnter a seed: ";
  cin >> seed;
  srand(seed);
  cout << "\nRandom numbers with seed " << seed << ":" << rand() << ", " << rand() << ", " << rand();
  return 0;
}

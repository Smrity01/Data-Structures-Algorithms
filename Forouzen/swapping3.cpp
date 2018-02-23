/* Demostrate the Swaping of Two values using xor operator
   Written by: Smrity Chaudhary
   Date : 29/12/2017
*/
#include<iostream>
using namespace std;

void swapping(int&,int&);
int main(){
    int num1;
    int num2;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "\nEnter another number: ";
    cin >> num2;
    swapping(num1,num2);
    cout << "\nFirst number is: " << num1;
    cout << "\nsecond number is: " << num2;
    return 0;
}
void swapping(int& num1,int& num2){
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}

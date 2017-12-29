/* Maximum of 3 elements using only one if-else statement
   Written by: Smrity Chaudhary
   Date : 29/12/2017
*/
#include<iostream>
using namespace std;

int maximum(int,int,int);
int max_of_two(int,int);
int main(){
    int num1;
    int num2;
    int num3;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "\nEnter second number: ";
    cin >> num2;
    cout << "\nEnter third number: ";
    cin >> num3;
    cout << "\nMaximum number is: " << maximum(num1,num2,num3);
    return 0;
}
int maximum(int num1,int num2,int num3){
    return (max_of_two(num1,max_of_two(num2,num3)));
}
int max_of_two(int num1,int num2){
    if (num1 > num2)
        return num1;
    else return num2;
}

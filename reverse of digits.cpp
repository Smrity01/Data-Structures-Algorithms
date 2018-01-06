/*
Reverse the digits of a number
   written by: Smrity chaudhary
   Date : 6-1-18
*/
#include<iostream>
using namespace std;

int reverse_digit(int);
int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "reverse of digits: " << reverse_digit(num);
}
int reverse_digit(int num){
    int reversed = 0;
    while (num != 0){
            reversed = reversed * 10;
        reversed = reversed + (num % 10);
        num = num / 10;
    }
    return reversed;
}

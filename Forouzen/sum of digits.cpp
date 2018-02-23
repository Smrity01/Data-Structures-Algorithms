/*
Sum of digits of a number
   written by: Smrity chaudhary
   Date : 6-1-18
*/
#include<iostream>
using namespace std;

int sum(int);
int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Sum of digits: " << sum(num);
}
int sum(int num){
    int total =0;
    while (num!=0){
        total = total + (num%10);
        num = num/10;
    }
    return total;
}

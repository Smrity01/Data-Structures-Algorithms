/*
Find out the given number is power of 2 or not
   written by: Smrity chaudhary
   Date : 3-1-18
*/
#include<iostream>
using namespace std;

int power(int);
int main(){
    float num;
    int result;
    cout << "Enter a number: ";
    cin >> num;
    if (0 < num && num < 1){
        num = 1 / num;
    }
    result = power(num);
    if (result == num){
            cout << "\nIt is a power of 2 " << num;
    }
    else{
        cout << "\nIt is NOT a power of 2 " << num;
    }
}

int power(int num){
    return (num & ~(num-1));
}

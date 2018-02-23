/*
Find out the given number is power of 2 or not
   written by: Smrity chaudhary
   Date : 2-1-18
*/
#include<iostream>
using namespace std;

int power(int);
int main(){
    float num;
    cout << "Enter a number: ";
    cin >> num;
    if (0 < num && num < 1){
        num = 1 / num;
    }
    num = power(num);
    if (num != 2){
        cout << "\nIt is Not a power of 2 ";
    }
    else{
        cout << "\nIt is a Power of 2";
    }
}
int power(int num){

    while(num != 2 ){
        if (num % 2 == 0){
            num = num / 2;
        }
        else{
            break;
            }
    }
    return num;
}

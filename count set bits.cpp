/*
Calculate the set bits in a number
   written by: Smrity chaudhary
   Date : 2-1-18
*/
#include<iostream>
using namespace std;

int binary(int);
int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Number of set bits: " << binary(num);
}
int binary(int num){
    int counter=0;
    while(num != 0){
        if(num % 2 == 1){
            counter++;
        }
        num = num / 2;
    }
    return counter;
}


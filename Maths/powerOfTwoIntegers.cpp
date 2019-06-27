/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where
P > 1 and A > 0. A and P both should be integers.
*/
#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

int isPower(int A);
int main(){
    cout << endl << isPower(1);
}
int isPower(int A) {
    float value;
    for (int i = 2; i <= sqrt(A); i++){
        value = log(A) / log(i);
        //cout << "\nvalue: " << abs(floor(value) - value);
        if (abs(floor(value) - value) == 0){
            return 1;
        }
        
    }
    return 0;
}

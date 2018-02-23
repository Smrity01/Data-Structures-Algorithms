/*
Fibonacci series using iterative approach
   written by : Smrity Chaudhary
   Dated      : 29/01/18
*/
#include<iostream>
using namespace std;

int fibonacci(int);
int main(){
    int number;
    cout << "which number of fibonacci series you want: ";
    cin >> number;
    cout << "Fibonacci number at given position is " << fibonacci(number);
    return 0;
}
int fibonacci(int number){
    if(number == 0){
        return 0;
    }
    else if( number == 1){
        return 1;
    }
    else{
            int low = 0;
            int high = 1;
            int next;
        for(int i = 2; i <= number ; i++){
             next = low + high;
             low = high;
             high = next;
        }
        return next;
    }
}

/*
Fibonacci series using iterative approach (array)
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
            int fib[number];
            fib[0] = 0;
            fib[1] = 1;
        for(int i = 2; i <= number ; i++){
             fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[number];
    }
}

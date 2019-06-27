/*
Test fibonacci calls
*/
#include<iostream>
using namespace std;

int fib(int);
int main(){
    int *fArray[5] = new int; 
    fib(5);
}
int fib(int n, int *fArray){
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 1;
    }

}
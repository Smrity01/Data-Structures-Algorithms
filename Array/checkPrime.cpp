#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;

void AllPrimeTillN(int A);
int isPrime(int A);
int main(){
    int A = 10;
    //isPrime(A);
    AllPrimeTillN(A);
}
int isPrime(int A) {
    if (A == 1 || A == -1) {
        return 0;
    }
    for (int i = 2; i < sqrt(abs(A))+1; i++){
        //cout << A%i << ",";
        if (A % i == 0) {
            return 0;
        }
    }
    return 1;
}
void AllPrimeTillN(int A){
    vector<int> factors;
    for (int i = 0; i <= A; i++){
        factors.push_back(1);
    }
    factors[0] = 0;
    factors[1] = 0;
    for (int i = 2; i <= sqrt(A); i++){
        /* because from 1 to n there will be multiples of only primes number[ <sqrt(n)] 
        */
        if(factors[i] == 1){
        for (int j = 2; i*j <= A; j++)
        {
            factors[i*j] = 0;
        }
        }
    }
    for (int i = 0; i <= A; i++){
        if (factors[i] == 1)
    }
}
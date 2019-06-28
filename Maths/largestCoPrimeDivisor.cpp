/*
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:
X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1

For example,
A = 30
B = 12
We return
X = 5
*/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int gcd(int A, int B);
int cpFact(int A, int B);
int main(){
    cout << "ans: " << cpFact(30,12);
}
int gcd(int A, int B){
    if (A == 0){
        return B;
    }
    if (B == 0){
        return A;
    }
    if (A == B){
        return A;
    }
    if (A > B){
        return gcd(A - B, B);
    }
    else{
        return gcd(A, B - A);
    }
}
int cpFact(int A, int B) {
    int currX = 1;
    for (int i = 1; i <= sqrt(A); i++){
        if (A % i == 0 ){
            if ( A / i != i){
                if (gcd(A / i, B) == 1){
                    currX = max(currX, A/i);
                    cout << "\n\ncurrX in A/i: " << currX << " A/i : " << A / i;
                }
            }
            if (gcd(i, B) == 1){
                currX = max(currX, i);
                cout << "currX in i: " << currX << " i : " << i;
            }
        }
    }
    return currX;
}
/*
ANOTHER APPROCH -------------- MORE EFFICIENT----------------------------
while (gcd(A,B) != 1){
    A = A / gcd(A,B);
}
return A;
 */
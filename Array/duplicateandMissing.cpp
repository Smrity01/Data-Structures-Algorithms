#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;
int repeatedNumber(vector<int> A);
int main(){
    vector<int> A;
    
    A.push_back(3);
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);
    A.push_back(5);
    
    repeatedNumber(A);
}
int repeatedNumber(vector<int> A) {
    int t = A[0];
    int sum = A[0];
    int sum2 = 0;
    for(int i = 1; i < A.size(); i++){
        t ^= A[i];
        sum += A[i];
    }
    for(int i = 1; i <= A.size(); i++){
        t ^= i;
        sum2 += i;    
    }
    int x;
    if(sum<sum2)
        x=sum2-sum;
    else
        x=sum-sum2;
    //int a;
    //int b;
    int a = x ^ t;
    cout <<   a;
    return -1;
}
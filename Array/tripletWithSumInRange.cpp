/*
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

int solve(vector<string> &A);
int main(){
    vector<string> A;
    A.push_back("0.6");
    A.push_back("0.7");
    A.push_back("0.8");
    A.push_back("1.2");
    A.push_back("0.4");
    solve(A);

}
int solve(vector<string> &A){
    float a = float(A[0]);
    float b = float(A[1]);
    float c = (float)(A[2]);
    for (int i = 0; i < A.size(); i++){
        cout << "";
    }
}
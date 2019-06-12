/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/2 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.
If there are multiple solutions, return any one.
*/
#include<iostream>
#include<vector>
using namespace std;

int repeatedNumber(const vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(10);
    A.push_back(10);
    A.push_back(15);
    A.push_back(15);
    A.push_back(10);
    A.push_back(10);
    A.push_back(10);
    A.push_back(15);
    A.push_back(10);
    A.push_back(15);
    cout << repeatedNumber(A);
}
int repeatedNumber(const vector<int> &A){
    int candidate = INT_MAX;
    int count = 0;
    for (int i = 0; i < A.size(); i++){
        if (count == 0){
            count = 1;
            candidate = A[i];
        }
        else if (A[i] == candidate){
            count++;
        }
        else{
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == candidate){
            count++;
        }
        
    }
    if (count > A.size() / 2){
        return candidate;
    }
    return -1;
}
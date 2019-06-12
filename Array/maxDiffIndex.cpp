/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
If there is no solution possible, return -1.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumGap(const vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(10);
    //A.push_back(3);
    //A.push_back(2);
    //A.push_back(4);
    /*
    A.push_back(15);
    A.push_back(10);
    A.push_back(10);
    A.push_back(10);
    */
    cout << maximumGap(A);
}
int maximumGap(const vector<int> &A){
    int *leftMin = new int[A.size()];
    int *rightMax = new int[A.size()];
    leftMin[0] = A[0];
    for (int i = 1; i < A.size(); i++){
        leftMin[i] = min(A[i] , leftMin[i - 1]);
    }
    rightMax[A.size() - 1] = A[A.size() - 1];
    for (int i = A.size() - 2; i >= 0; i--){
        rightMax[i] = max(A[i], rightMax[i + 1]);
    }
    int i = 0, j = 0, maxGap = -1;
    while (i < A.size() && j < A.size()){
        if (leftMin[i] <= rightMax[j]){
            maxGap = max(maxGap, j-i);
            j++;
        }
        else i++;
    }
    return maxGap;
}

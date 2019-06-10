/*
Given an array of N integers, A1, A2, …, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.
TIME COMPLEXITY : O(n)
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int maxArr(vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(-1);
    cout << "\nMAX VALUE: " << maxArr(A);
}
/*
TIME COMPLEXITY : O(n^2)
int maxArr(vector<int> &A) {
    int functionValue;
    int maxValue = INT_MIN;
    for (int i = 0; i < A.size() - 1; i++){
        for (int j = i+1; j < A.size(); j++){
            cout << "i,j: " << i << "," << j << endl;
            functionValue = abs(A[i] - A[j]) + abs(i - j);
            cout << functionValue << endl;
            if(maxValue < functionValue){
                maxValue = functionValue;
            }
        }
    }
    return maxValue;
}
*/
int maxArr(vector<int> &A) {
    int minValueSum = INT_MAX;
    int maxValueSum = INT_MIN;
    int maxValueDiff = INT_MIN;
    int minValueDiff = INT_MAX;
    for (int i = 0; i < A.size(); i++){
        minValueSum  = min(minValueSum, A[i] + i);
        maxValueSum  = max(maxValueSum, A[i] + i);
        minValueDiff  = min(minValueDiff, A[i] - i);
        maxValueDiff  = max(maxValueDiff, A[i] - i);
        //cout << maxValueDiff << " "<<minValueDiff << " " << maxValueSum << " " << minValueSum << endl;
    }
    return max(maxValueSum - minValueSum, maxValueDiff - minValueDiff);
}
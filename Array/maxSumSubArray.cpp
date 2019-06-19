/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B)
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> maxset(vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(-2);
    maxset(A);
}
vector<int> maxset(vector<int> &A) {
    long long maxSum = -1;
    int maxStart = -1;
    int maxEnd = -1;
    long long sum = 0;
    int start = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] < 0){
            sum = 0;
            start = i + 1;
        }
        else{
            sum = sum + A[i];
        }
        if (sum > maxSum){
            maxSum = sum;
            maxEnd = i;
            maxStart = start;
        }
        if ( sum == maxSum && maxEnd - maxStart + 1 < i - start + 1) {
            maxEnd = i;
            maxStart = start;
        }
    }
    vector<int> maxSubArray;
    if (start == A.size() - 1 && maxEnd == -1 || maxStart == -1){
        return maxSubArray;
    }
    for (int i = maxStart; i <= maxEnd; i++){
        maxSubArray.push_back(A[i]);
    }
    return maxSubArray;
}

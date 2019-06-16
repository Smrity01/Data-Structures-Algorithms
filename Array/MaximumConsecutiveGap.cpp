
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int maximumGap(const vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(2);
    A.push_back(4);
    A.push_back(8);
    A.push_back(11);
    cout << maximumGap(A);
}
int maximumGap(const vector<int> &A) {
    if (A.size() < 2){
        return 0;
    }
    int maxValue = A[0];
    int minValue = A[0];
    for (int i = 1; i < A.size(); i++){
        minValue = min(minValue, A[i]);
        maxValue = max(maxValue, A[i]);
    }
    int bucket1[A.size() - 1];
    int bucket2[A.size() - 1];
    fill_n(bucket1, A.size() - 1,INT_MIN);
    fill_n(bucket2, A.size() - 1,INT_MAX);
    float gap = (float)(maxValue - minValue) / (float)(A.size() - 1);
    for (int i = 0; i < A.size(); i++){
        if (A[i] == maxValue || A[i] == minValue){
            continue;
        }
        int index = (float)(floor(A[i] - minValue) / gap);
        if (bucket1[index] == INT_MIN){
            bucket1[index] = A[i];
        }
        else{
            bucket1[index] = max(bucket1[index], A[i]);
        }
        if (bucket2[index] == INT_MAX){
            bucket2[index] = A[i];
        }
        else{
            bucket2[index] = min(bucket2[index], A[i]);
        }
    }
    int prevValue = minValue;
    int maximumGap = 0;
    for (int i = 0; i < A.size() - 1; i++){
        if(bucket2[i] == INT_MAX){
            continue;
        }
        maximumGap = max(maximumGap, bucket2[i] - prevValue);
        prevValue = bucket1[i];
    }
    maximumGap = max(maximumGap, maxValue - prevValue);
    return maximumGap;
}
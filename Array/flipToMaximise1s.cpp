/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters 
S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N 
and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.
Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. 
If you don’t want to perform the operation, return an empty array. Else, return an array consisting
of two elements denoting L and R. If there are multiple solutions, return the lexicographically 
smallest pair of L and R.
Notes:
Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.TIME COMPLEXITY : O(n)
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

vector<int> flipZeros(vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    flipZeros(A);
}
vector<int> flipZeros(vector<int> &A){
    int leftIndex = 0;
    int rightIndex = 0;
    int sum = 0;
    int maxSum = 0;
    
    vector<int> resultPair;
    //resultPair.push_back(-1);
    //resultPair.push_back(-1);
    for (int i = 0; i < A.size(); i++){
        if (A[i] == 0){
            sum++;
        }
        else{
            sum --;
        }
        if (sum < 0){
            sum = 0;
            leftIndex = i+1;
        }
        if (sum > maxSum){
            maxSum = sum;
            if (resultPair.size() > 1){
                resultPair.pop_back();
                resultPair.pop_back();
            }
            resultPair.push_back(leftIndex);
            resultPair.push_back(i); 
            rightIndex = i;
        }
    }
    if (resultPair.size() > 1){
        resultPair[0] += 1;
        resultPair[1] += 1; 
    }
    //cout << resultPair[0] << " " << resultPair[1];
    return resultPair;
}
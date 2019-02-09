/*
Find largest sum of contiguous sub-array
Complexity : O(n)
Written By : Smrity Chaudhary
Dated 	   : 09/02/2019
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int maxSubArray(const vector<int> &Array);
int main() {
    vector<int> Array;
    int vectorSize;
    cout << "Enter the length of your array: ";
    cin >> vectorSize;
    int element;
    cout << "Enter your Array: ";
    for (int i = 0; i < vectorSize; i++){
        cin >> element;
        Array.push_back(element);
    }
    cout << "Largest contiguous sub-array sum:  " <<maxSubArray(Array);
}
int maxSubArray(const vector<int> &Array) {
    int SumTillnow = 0;
    int MaximumSofar = Array[0];
    for (int i = 0; i < Array.size(); i++) {
        SumTillnow = SumTillnow + Array[i];
        if (MaximumSofar < SumTillnow) {
            MaximumSofar = SumTillnow;
        }
        if (SumTillnow < 0) {
            SumTillnow = 0;
        }
    }
    return MaximumSofar;
}

/*
Find largest sum of contiguous sub-array
Complexity : O(n^2)
Written By : Smrity Chaudhary
Dated 	   : 09/02/2019
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int maxInArray(vector<int> subArray);
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
    cout << "Largest contiguous subarray sum:  " << maxSubArray(Array);
}
int maxSubArray(const vector<int> &Array) {
    int largestSum = Array[0];
    for (int i = 0; i < Array.size(); i++) {
            vector<int> sumArray;
            for (int j = i; j < Array.size(); j++) {
                if (j == i) {
                    sumArray.push_back(Array[j]);
                }
                else {
                sumArray.push_back(sumArray[sumArray.size() - 1] + Array[j]);
                }
            }
          int maxElement = maxInArray(sumArray);
          if (largestSum < maxElement)
            largestSum = maxElement;
          sumArray.clear();

    }
    return largestSum;
}

int maxInArray(vector<int> subArray) {
    int maxElement = subArray[0];
    for (int i = 1; i < subArray.size(); i++){
        if (maxElement < subArray[i])
            maxElement = subArray[i];

    }
    return maxElement;
    return maxElement;

}

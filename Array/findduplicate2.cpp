#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
#include <unordered_map>
using namespace std;
int repeatedNumber(vector<int> A);
int main(){
    vector<int> A;
    
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
    A.push_back(4);
    A.push_back(1);
    
    cout << repeatedNumber(A);
}
int repeatedNumber(vector<int> A) {
    int blockSize = sqrt(A.size());
    int ranges = (A.size()/blockSize) + 1;
    int countArray[ranges] = {0};
    int counter = 0;
    int index = 0;
    for (int i = 0; i < A.size(); i++){
        countArray[(A[i]-1)/blockSize]++;
    }
    int selectedBlock = ranges - 1;
    for (int i = 0; i < ranges - 1; i++){
        if (countArray > blockSize){
            selectedBlock = i;
            break;
        }
    }
    unordered_map<int, int> elementCounts;
    for (int i = 0; i < A.size(); i++){
        if( (selectedBlock * blockSize) < A[i] && A[i] <= ((selectedBlock + 1) * blockSize)){
            elementCounts[A[i]]++;
            if (elementCounts[A[i]] > 1 ){
                return A[i];
            }
        }
    }
    return -1;
}
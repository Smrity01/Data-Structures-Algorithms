/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
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
    A.push_back(10);
    //A.push_back(15);
    A.push_back(10);
    A.push_back(10);
    A.push_back(15);
    A.push_back(10);
    A.push_back(15);
    cout << repeatedNumber(A);
}
int repeatedNumber(const vector<int> &A){
    int candidate1 = INT_MAX;
    int candidate2 = INT_MAX;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == candidate1){
            count1++;
        }
        else if (A[i] == candidate2){
            count2++;
        }
        else if (count1 == 0){
            count1++;
            candidate1 = A[i];
        }
        else if (count2 == 0){
            count2++;
            candidate2 = A[i];
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < A.size(); i++){
        if (A[i] == candidate1){
            count1++;
        }
        if (A[i] == candidate2){
            count2++;
        }
    }
    if (count1 > A.size() / 3){
        return candidate1;
    }
    if (count2 > A.size() / 3){
        return candidate2;
    }
    return -1;
}
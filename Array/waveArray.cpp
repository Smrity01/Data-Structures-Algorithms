/*
Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> makeWave(vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(5);
    A.push_back(1);
    A.push_back(3);
    A.push_back(2);
    A.push_back(4);/*
    A.push_back(15);
    A.push_back(10);
    A.push_back(10);
    A.push_back(10);
    */
    makeWave(A);
    for (int i = 0; i < A.size(); i++){
        cout << A[i] << ",";
    }
}
vector<int> makeWave(vector<int> &A){
    int temp;
    if (A.size() < 2){
        return A;
    }
    /* if it does not pass the test case, then uncomment the statement below.
    they might expecting - [2, 1, 4, 3, 5 ] instead of [5, 1, 3, 2, 4]
    */
    //sort (A.begin(); A.end());
    for (int i = 0; i < A.size(); i = i + 2){
        if ( i > 0 && A[i] < A[i - 1]){
            temp = A[i];
            A[i] = A[i - 1];
            A[i - 1] = temp;
        }
        if ( i < A.size() - 1 && A[i] < A[i + 1]){
            temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
        }
    }
    return A;
}
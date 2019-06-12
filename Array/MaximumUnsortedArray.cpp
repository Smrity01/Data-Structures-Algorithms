/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> subUnsort(vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(10);
    A.push_back(10);
    A.push_back(15);
    A.push_back(10);
    A.push_back(15);
    A.push_back(10);
    A.push_back(10);
    A.push_back(15);
    A.push_back(10);
    A.push_back(15);
    //A.push_back(4);
    //A.push_back(5);
    subUnsort(A);
}
vector<int> subUnsort(vector<int> & A){
    vector<int> index;
    int start = -1;
    int end = -1;
    for (int i = 0; i < A.size() - 1; i++){
        if(A[i + 1] < A[i]){
            start = i;
            break;
        }
    }
    for (int i = A.size() - 1; i > 0; i--){
        if(A[i] < A[i-1]){
            end = i;
            break;
        }
    }
    if (start != -1 && end != -1){
        int min = A[start];
        int max = A[start];
        for (int i = start; i <= end; i++){
            if (A[i] > max){
                max = A[i];
            }
            if (A[i] < min){
                min = A[i];
            }
        }
        for (int i = 0; i < start; i++){
            if (A[i] > min){
                start = i;
                break;
            }
        }
        for (int i = A.size() - 1; i > end; i--){
            if (A[i] < max){
                end = i;
                break;
            }
        }
        index.push_back(start);
        index.push_back(end);
        //cout << "\nstart: " << start << " ENd: " << end << endl;
    }
    else {
        index.push_back(-1);
    }
    //cout << "\n when sorted: "<< index[0]  << " " <<index[1] << " size: " << index.size();
    return index;
}

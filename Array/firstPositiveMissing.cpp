#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int firstPositiveMissing(vector<int> A);
int segregateIntegers(vector<int> &A);
int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    cout << firstPositiveMissing(A);
}
int firstPositiveMissing(vector<int> A){
    bool flag = true;
    for (int i = 0 ; i<A.size(); i++){
        flag = flag && (A[i] < 0);
    }
    if(flag == true){
        return 1;
    }
    int shift = segregateIntegers(A);
    for (int i = shift ; i < A.size(); i++){
        if(abs(A[i]) -1+shift< (A.size()) && A[abs(A[i])-1+shift] > 0 ){
            A[abs(A[i])-1+shift] = -A[abs(A[i])-1+shift]; 
        }
    }
    for (int i = 0 ; i<A.size(); i++){
        cout << A[i] << endl;
    }
    int i;
    for (i = 0 ; i<A.size(); i++){
        if(A[i] > 0 ){
            return abs(i+1 - shift);
        }
    }
    return i + 1;
}
int segregateIntegers(vector<int> &A){
    int i = 0;
    int j = A.size()-1;
    while(i<=j){
        if(A[j] < 0){
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i++;
        }
        else{
            j--;
        }
    }
    return i;
}


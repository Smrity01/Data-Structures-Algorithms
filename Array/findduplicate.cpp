#include<iostream>
#include<vector>
#include <stdlib.h>
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
    for(int i = 0; i < A.size(); i++){
        if(A[abs(A[i])] > 0){
            A[abs(A[i])] = -A[abs(A[i])];
            //A.insert(i,-A[A[i]]);
        }
        else{
            return abs(A[i]);
        }
    }
    return -1;
}
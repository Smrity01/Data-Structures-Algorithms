/*
Search element in an sorted array which is rotated any number of times.
TIME COMPLEXITY : O(log n)
*/
#include<iostream>
#include<vector>
using namespace std;

int binarySearchRotated(vector<int> A, int first, int last, int element);
int main(){
    vector<int> A;
    A.push_back(19);
    A.push_back(20);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);    
    cout << binarySearchRotated(A, 0, A.size()-1, 4);
}
int binarySearchRotated(vector<int> A, int first, int last, int element){
    int mid;
    mid = first + (last - first)/2;
    if ( first > last){
        return -1;
    }
    if(A[mid] == element){
        return mid;
    }
    if(A[first] <= A[mid]){
        if(element >= A[first] && element < A[mid]){
            return binarySearchRotated(A, first, mid - 1, element);
        }
        else
        {
            return binarySearchRotated(A, mid + 1, last, element);
        }
        
    }
    else{
        if(element <= A[last] && element > A[mid]){
            return binarySearchRotated(A, mid + 1, last, element);
        }
        else
        {
            return binarySearchRotated(A, first, mid - 1, element);
        }
    }
    
    return -1;
}
/*
An array is bitonic if it is comprised of increasing sequence of integers and followed
immediately by a decreasing Sequence of integers.
Find that point.
Time complexity : O(log n)
*/
#include<iostream>
#include<vector>
using namespace std;

int bitonicSearch(vector<int> A);
int main(){
    vector<int> A;
    A.push_back(19);
    A.push_back(20);
    A.push_back(18);
    A.push_back(12);
    A.push_back(11);
    A.push_back(10);
    A.push_back(9);
    cout << bitonicSearch(A);
}
int bitonicSearch(vector<int> A){
    int mid;
    int first = 0;
    int last = A.size() - 1;
    while( first <= last){
        if (first == last){
            return first;
        }
        else if (first == last - 1){
            return A[first] > A[last] ? first : last;
        }
        else{
            mid  = first + (last - first)/2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){
                return mid;
            }
            else if(A[mid - 1] < A[mid] && A[mid + 1] > A[mid]){
                first = mid + 1;
            }
            else if (A[mid - 1] > A[mid] && A[mid + 1] < A[mid]){
                last = mid - 1;
            }
            else {
                return -1;
            }
        }
    }
}

/*
Implementation of merge sort
Written By: Smrity Chaudhary
Dated     : 09/10/2018
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void merging(vector<int> &,int,int,int);
void mergesort(vector<int> &, int,int);
int main(){
    /*
    Objective       : Take input in vector and call other functions
    Input Parameter : None
    Output Value    : Sorted Array
    Description     : Driver function
    */
    int element;
    vector<int> element_list;
    char choice = 'y';
    while(choice == 'y' || choice == 'Y' ){
        cout << "Enter an element: ";
        cin >> element;
        element_list.push_back(element);
        cout << "Do you want to enter more?(y/n): ";
        cin >> choice;
    }
    mergesort(element_list,0,element_list.size()-1);
    cout << " Sorted array: ";
    for ( int i=0;i<element_list.size();i++){
        cout << element_list[i]<< " ";
    }
    return 0;
}
void mergesort(vector<int> &elist,int p,int r){
    /*
    Objective       : Sort the given list of elements
    Input Parameter : List of elements in vector, first and last position
    Output Value    : None
    Approach        : Merge sort divide the list into two sublist,an then merge
                      them in a sorted manner
    */
    if(p<r){
        // divide list into two sub-list
        int q = floor((p+r)/2);
        mergesort(elist,p,q);
        mergesort(elist,q+1,r);
        merging(elist,p,q,r);
    }
}
void merging(vector<int> &elist,int p,int q,int r){
    /*
    Objective       : Merge two list of elements
    Input Parameter : List of elements in vector, first, middle and last position
    Output Value    : None
    Approach        : Element of both sub-lists are compared and smaller element
                      will be inserted into the original list
    */
    int size1 = q-p+1;
    int size2 = r-q;
    int left[size1];
    int right[size2];
    //Copy elements into left and right sub-list
    for(int i=0;i<size1;i++){
        left[i] = elist[i];
    }
    for(int i=0;i<size2;i++){
        right[i] = elist[i+q+1];
    }
    int j = 0,k = 0;
    //compared elements of both sub-list
    for(int i = p;i<=r;i++){
          if(left[j]<right[k]){
            elist[i] = left[j];
            j++;
        }
        else{
            elist[i] = right[k];
            k++;
        }
    }
    return;
}
